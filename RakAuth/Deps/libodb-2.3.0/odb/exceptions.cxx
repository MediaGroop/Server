// file      : odb/exceptions.cxx
// copyright : Copyright (c) 2009-2013 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#include <sstream>
#include <odb/exceptions.hxx>

using namespace std;

namespace odb
{
  const char* null_pointer::
  what () const throw ()
  {
    return "NULL pointer";
  }

  const char* already_in_transaction::
  what () const throw ()
  {
    return "transaction already in progress in this thread";
  }

  const char* not_in_transaction::
  what () const throw ()
  {
    return "operation can only be performed in transaction";
  }

  const char* transaction_already_finalized::
  what () const throw ()
  {
    return "transaction already committed or rolled back";
  }

  const char* already_in_session::
  what () const throw ()
  {
    return "session already in effect in this thread";
  }

  const char* not_in_session::
  what () const throw ()
  {
    return "session not in effect in this thread";
  }

  const char* session_required::
  what () const throw ()
  {
    return "session required to load this object relationship";
  }

  const char* deadlock::
  what () const throw ()
  {
    return "transaction aborted due to deadlock";
  }

  const char* connection_lost::
  what () const throw ()
  {
    return "connection to database lost";
  }

  const char* timeout::
  what () const throw ()
  {
    return "database operation timeout";
  }

  const char* object_not_persistent::
  what () const throw ()
  {
    return "object not persistent";
  }

  const char* object_already_persistent::
  what () const throw ()
  {
    return "object already persistent";
  }

  const char* object_changed::
  what () const throw ()
  {
    return "object changed concurrently";
  }

  const char* result_not_cached::
  what () const throw ()
  {
    return "query result is not cached";
  }

  const char* abstract_class::
  what () const throw ()
  {
    return "database operation on instance of abstract class";
  }

  const char* no_type_info::
  what () const throw ()
  {
    return "no type information";
  }

  prepared_already_cached::
  prepared_already_cached (const char* name)
      : name_ (name)
  {
    what_ = "prepared query '";
    what_ += name;
    what_ += "' is already cached";
  }

  prepared_already_cached::
  ~prepared_already_cached () throw ()
  {
  }

  const char* prepared_already_cached::
  what () const throw ()
  {
    return what_.c_str ();
  }

  prepared_type_mismatch::
  prepared_type_mismatch (const char* name)
      : name_ (name)
  {
    what_ = "type mismatch while looking up prepared query '";
    what_ += name;
    what_ += "'";
  }

  prepared_type_mismatch::
  ~prepared_type_mismatch () throw ()
  {
  }

  const char* prepared_type_mismatch::
  what () const throw ()
  {
    return what_.c_str ();
  }

  unknown_schema::
  unknown_schema (const std::string& name)
      : name_ (name)
  {
    what_ = "unknown database schema '";
    what_ += name;
    what_ += "'";
  }

  unknown_schema::
  ~unknown_schema () throw ()
  {
  }

  const char* unknown_schema::
  what () const throw ()
  {
    return what_.c_str ();
  }

  unknown_schema_version::
  unknown_schema_version (schema_version v)
      : version_ (v)
  {
    ostringstream os;
    os << v;
    what_ = "unknown database schema version ";
    what_ += os.str ();
  }

  unknown_schema_version::
  ~unknown_schema_version () throw ()
  {
  }

  const char* unknown_schema_version::
  what () const throw ()
  {
    return what_.c_str ();
  }

  const char* section_not_loaded::
  what () const throw ()
  {
    return "section is not loaded";
  }

  const char* section_not_in_object::
  what () const throw ()
  {
    return "section instance is not part of an object (section was copied?)";
  }
}
