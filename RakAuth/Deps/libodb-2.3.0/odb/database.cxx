// file      : odb/database.cxx
// copyright : Copyright (c) 2009-2013 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#include <odb/database.hxx>

#include <odb/details/lock.hxx>

using namespace std;

namespace odb
{
  using details::lock;

  database::
  ~database ()
  {
  }

  unsigned long long database::
  execute (const char* st, std::size_t n)
  {
    connection_type& c (transaction::current ().connection ());
    return c.execute (st, n);
  }

  const database::schema_version_migration_type& database::
  schema_version_migration (const string& name) const
  {
    lock l (mutex_); // Prevents concurrent loading.

    schema_version_map::const_iterator i (schema_version_map_.find (name));
    return i != schema_version_map_.end () && i->second.version != 0
      ? i->second
      : load_schema_version (name);
  }

  void database::
  schema_version_migration (const schema_version_migration_type& svm,
                            const string& name)
  {
    // Note: no lock, not thread-safe.

    schema_version_info& svi (schema_version_map_[name]);
    if (svi.version != svm.version || svi.migration != svm.migration)
    {
      svi.version = svm.version;
      svi.migration = svm.migration;
      schema_version_seq_++;
    }
  }
}
