// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#include <odb/pre.hxx>

#include "AccountInfo-odb.hxx"

#include <cassert>
#include <cstring>  // std::memcpy


#include <odb/pgsql/traits.hxx>
#include <odb/pgsql/database.hxx>
#include <odb/pgsql/transaction.hxx>
#include <odb/pgsql/connection.hxx>
#include <odb/pgsql/statement.hxx>
#include <odb/pgsql/statement-cache.hxx>
#include <odb/pgsql/simple-object-statements.hxx>
#include <odb/pgsql/container-statements.hxx>
#include <odb/pgsql/exceptions.hxx>
#include <odb/pgsql/simple-object-result.hxx>

namespace odb
{
  // AccountInfo
  //

  const char access::object_traits_impl< ::AccountInfo, id_pgsql >::
  persist_statement_name[] = "AccountInfo_persist";

  const char access::object_traits_impl< ::AccountInfo, id_pgsql >::
  find_statement_name[] = "AccountInfo_find";

  const char access::object_traits_impl< ::AccountInfo, id_pgsql >::
  update_statement_name[] = "AccountInfo_update";

  const char access::object_traits_impl< ::AccountInfo, id_pgsql >::
  erase_statement_name[] = "AccountInfo_erase";

  const char access::object_traits_impl< ::AccountInfo, id_pgsql >::
  query_statement_name[] = "AccountInfo_query";

  const char access::object_traits_impl< ::AccountInfo, id_pgsql >::
  erase_query_statement_name[] = "AccountInfo_erase_query";

  const unsigned int access::object_traits_impl< ::AccountInfo, id_pgsql >::
  persist_statement_types[] =
  {
    pgsql::text_oid,
    pgsql::bytea_oid,
    pgsql::text_oid,
    pgsql::bool_oid,
    pgsql::bool_oid
  };

  const unsigned int access::object_traits_impl< ::AccountInfo, id_pgsql >::
  find_statement_types[] =
  {
    pgsql::text_oid
  };

  const unsigned int access::object_traits_impl< ::AccountInfo, id_pgsql >::
  update_statement_types[] =
  {
    pgsql::bytea_oid,
    pgsql::text_oid,
    pgsql::bool_oid,
    pgsql::bool_oid,
    pgsql::text_oid
  };

  struct access::object_traits_impl< ::AccountInfo, id_pgsql >::extra_statement_cache_type
  {
    extra_statement_cache_type (
      pgsql::connection&,
      image_type&,
      pgsql::binding&,
      pgsql::binding&,
      pgsql::native_binding&,
      const unsigned int*)
    {
    }
  };

  access::object_traits_impl< ::AccountInfo, id_pgsql >::id_type
  access::object_traits_impl< ::AccountInfo, id_pgsql >::
  id (const image_type& i)
  {
    pgsql::database* db (0);
    ODB_POTENTIALLY_UNUSED (db);

    id_type id;
    {
      pgsql::value_traits<
          ::std::string,
          pgsql::id_string >::set_value (
        id,
        i.login_value,
        i.login_size,
        i.login_null);
    }

    return id;
  }

  bool access::object_traits_impl< ::AccountInfo, id_pgsql >::
  grow (image_type& i,
        bool* t)
  {
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (t);

    bool grew (false);

    // login_
    //
    if (t[0UL])
    {
      i.login_value.capacity (i.login_size);
      grew = true;
    }

    // password_
    //
    if (t[1UL])
    {
      i.password_value.capacity (i.password_size);
      grew = true;
    }

    // mail_
    //
    if (t[2UL])
    {
      i.mail_value.capacity (i.mail_size);
      grew = true;
    }

    // premium_
    //
    t[3UL] = 0;

    // beta_
    //
    t[4UL] = 0;

    return grew;
  }

  void access::object_traits_impl< ::AccountInfo, id_pgsql >::
  bind (pgsql::bind* b,
        image_type& i,
        pgsql::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace pgsql;

    std::size_t n (0);

    // login_
    //
    if (sk != statement_update)
    {
      b[n].type = pgsql::bind::text;
      b[n].buffer = i.login_value.data ();
      b[n].capacity = i.login_value.capacity ();
      b[n].size = &i.login_size;
      b[n].is_null = &i.login_null;
      n++;
    }

    // password_
    //
    b[n].type = pgsql::bind::bytea;
    b[n].buffer = i.password_value.data ();
    b[n].capacity = i.password_value.capacity ();
    b[n].size = &i.password_size;
    b[n].is_null = &i.password_null;
    n++;

    // mail_
    //
    b[n].type = pgsql::bind::text;
    b[n].buffer = i.mail_value.data ();
    b[n].capacity = i.mail_value.capacity ();
    b[n].size = &i.mail_size;
    b[n].is_null = &i.mail_null;
    n++;

    // premium_
    //
    b[n].type = pgsql::bind::boolean_;
    b[n].buffer = &i.premium_value;
    b[n].is_null = &i.premium_null;
    n++;

    // beta_
    //
    b[n].type = pgsql::bind::boolean_;
    b[n].buffer = &i.beta_value;
    b[n].is_null = &i.beta_null;
    n++;
  }

  void access::object_traits_impl< ::AccountInfo, id_pgsql >::
  bind (pgsql::bind* b, id_image_type& i)
  {
    std::size_t n (0);
    b[n].type = pgsql::bind::text;
    b[n].buffer = i.id_value.data ();
    b[n].capacity = i.id_value.capacity ();
    b[n].size = &i.id_size;
    b[n].is_null = &i.id_null;
  }

  bool access::object_traits_impl< ::AccountInfo, id_pgsql >::
  init (image_type& i,
        const object_type& o,
        pgsql::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace pgsql;

    bool grew (false);

    // login_
    //
    if (sk == statement_insert)
    {
      ::std::string const& v =
        o.login_;

      bool is_null (false);
      std::size_t size (0);
      std::size_t cap (i.login_value.capacity ());
      pgsql::value_traits<
          ::std::string,
          pgsql::id_string >::set_image (
        i.login_value,
        size,
        is_null,
        v);
      i.login_null = is_null;
      i.login_size = size;
      grew = grew || (cap != i.login_value.capacity ());
    }

    // password_
    //
    {
      unsigned char const* v =
        o.password_;

      bool is_null (false);
      std::size_t size (0);
      std::size_t cap (i.password_value.capacity ());
      pgsql::value_traits<
          unsigned char[20],
          pgsql::id_bytea >::set_image (
        i.password_value,
        size,
        is_null,
        v);
      i.password_null = is_null;
      i.password_size = size;
      grew = grew || (cap != i.password_value.capacity ());
    }

    // mail_
    //
    {
      ::std::string const& v =
        o.mail_;

      bool is_null (false);
      std::size_t size (0);
      std::size_t cap (i.mail_value.capacity ());
      pgsql::value_traits<
          ::std::string,
          pgsql::id_string >::set_image (
        i.mail_value,
        size,
        is_null,
        v);
      i.mail_null = is_null;
      i.mail_size = size;
      grew = grew || (cap != i.mail_value.capacity ());
    }

    // premium_
    //
    {
      bool const& v =
        o.premium_;

      bool is_null (false);
      pgsql::value_traits<
          bool,
          pgsql::id_boolean >::set_image (
        i.premium_value, is_null, v);
      i.premium_null = is_null;
    }

    // beta_
    //
    {
      bool const& v =
        o.beta_;

      bool is_null (false);
      pgsql::value_traits<
          bool,
          pgsql::id_boolean >::set_image (
        i.beta_value, is_null, v);
      i.beta_null = is_null;
    }

    return grew;
  }

  void access::object_traits_impl< ::AccountInfo, id_pgsql >::
  init (object_type& o,
        const image_type& i,
        database* db)
  {
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (db);

    // login_
    //
    {
      ::std::string& v =
        o.login_;

      pgsql::value_traits<
          ::std::string,
          pgsql::id_string >::set_value (
        v,
        i.login_value,
        i.login_size,
        i.login_null);
    }

    // password_
    //
    {
      unsigned char* v =
        o.password_;

      pgsql::value_traits<
          unsigned char[20],
          pgsql::id_bytea >::set_value (
        v,
        i.password_value,
        i.password_size,
        i.password_null);
    }

    // mail_
    //
    {
      ::std::string& v =
        o.mail_;

      pgsql::value_traits<
          ::std::string,
          pgsql::id_string >::set_value (
        v,
        i.mail_value,
        i.mail_size,
        i.mail_null);
    }

    // premium_
    //
    {
      bool& v =
        o.premium_;

      pgsql::value_traits<
          bool,
          pgsql::id_boolean >::set_value (
        v,
        i.premium_value,
        i.premium_null);
    }

    // beta_
    //
    {
      bool& v =
        o.beta_;

      pgsql::value_traits<
          bool,
          pgsql::id_boolean >::set_value (
        v,
        i.beta_value,
        i.beta_null);
    }
  }

  void access::object_traits_impl< ::AccountInfo, id_pgsql >::
  init (id_image_type& i, const id_type& id)
  {
    bool grew (false);
    {
      bool is_null (false);
      std::size_t size (0);
      std::size_t cap (i.id_value.capacity ());
      pgsql::value_traits<
          ::std::string,
          pgsql::id_string >::set_image (
        i.id_value,
        size,
        is_null,
        id);
      i.id_null = is_null;
      i.id_size = size;
      grew = grew || (cap != i.id_value.capacity ());
    }

    if (grew)
      i.version++;
  }

  const char access::object_traits_impl< ::AccountInfo, id_pgsql >::persist_statement[] =
  "INSERT INTO \"AccountInfo\" "
  "(\"login\", "
  "\"password\", "
  "\"mail\", "
  "\"premium\", "
  "\"beta\") "
  "VALUES "
  "($1, $2, $3, $4, $5)";

  const char access::object_traits_impl< ::AccountInfo, id_pgsql >::find_statement[] =
  "SELECT "
  "\"AccountInfo\".\"login\", "
  "\"AccountInfo\".\"password\", "
  "\"AccountInfo\".\"mail\", "
  "\"AccountInfo\".\"premium\", "
  "\"AccountInfo\".\"beta\" "
  "FROM \"AccountInfo\" "
  "WHERE \"AccountInfo\".\"login\"=$1";

  const char access::object_traits_impl< ::AccountInfo, id_pgsql >::update_statement[] =
  "UPDATE \"AccountInfo\" "
  "SET "
  "\"password\"=$1, "
  "\"mail\"=$2, "
  "\"premium\"=$3, "
  "\"beta\"=$4 "
  "WHERE \"login\"=$5";

  const char access::object_traits_impl< ::AccountInfo, id_pgsql >::erase_statement[] =
  "DELETE FROM \"AccountInfo\" "
  "WHERE \"login\"=$1";

  const char access::object_traits_impl< ::AccountInfo, id_pgsql >::query_statement[] =
  "SELECT "
  "\"AccountInfo\".\"login\", "
  "\"AccountInfo\".\"password\", "
  "\"AccountInfo\".\"mail\", "
  "\"AccountInfo\".\"premium\", "
  "\"AccountInfo\".\"beta\" "
  "FROM \"AccountInfo\"";

  const char access::object_traits_impl< ::AccountInfo, id_pgsql >::erase_query_statement[] =
  "DELETE FROM \"AccountInfo\"";

  const char access::object_traits_impl< ::AccountInfo, id_pgsql >::table_name[] =
  "\"AccountInfo\"";

  void access::object_traits_impl< ::AccountInfo, id_pgsql >::
  persist (database& db, const object_type& obj)
  {
    ODB_POTENTIALLY_UNUSED (db);

    using namespace pgsql;

    pgsql::connection& conn (
      pgsql::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    callback (db,
              obj,
              callback_event::pre_persist);

    image_type& im (sts.image ());
    binding& imb (sts.insert_image_binding ());

    if (init (im, obj, statement_insert))
      im.version++;

    if (im.version != sts.insert_image_version () ||
        imb.version == 0)
    {
      bind (imb.bind, im, statement_insert);
      sts.insert_image_version (im.version);
      imb.version++;
    }

    insert_statement& st (sts.persist_statement ());
    if (!st.execute ())
      throw object_already_persistent ();

    callback (db,
              obj,
              callback_event::post_persist);
  }

  void access::object_traits_impl< ::AccountInfo, id_pgsql >::
  update (database& db, const object_type& obj)
  {
    ODB_POTENTIALLY_UNUSED (db);

    using namespace pgsql;
    using pgsql::update_statement;

    callback (db, obj, callback_event::pre_update);

    pgsql::transaction& tr (pgsql::transaction::current ());
    pgsql::connection& conn (tr.connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    const id_type& id (
      obj.login_);
    id_image_type& idi (sts.id_image ());
    init (idi, id);

    image_type& im (sts.image ());
    if (init (im, obj, statement_update))
      im.version++;

    bool u (false);
    binding& imb (sts.update_image_binding ());
    if (im.version != sts.update_image_version () ||
        imb.version == 0)
    {
      bind (imb.bind, im, statement_update);
      sts.update_image_version (im.version);
      imb.version++;
      u = true;
    }

    binding& idb (sts.id_image_binding ());
    if (idi.version != sts.update_id_image_version () ||
        idb.version == 0)
    {
      if (idi.version != sts.id_image_version () ||
          idb.version == 0)
      {
        bind (idb.bind, idi);
        sts.id_image_version (idi.version);
        idb.version++;
      }

      sts.update_id_image_version (idi.version);

      if (!u)
        imb.version++;
    }

    update_statement& st (sts.update_statement ());
    if (st.execute () == 0)
      throw object_not_persistent ();

    callback (db, obj, callback_event::post_update);
    pointer_cache_traits::update (db, obj);
  }

  void access::object_traits_impl< ::AccountInfo, id_pgsql >::
  erase (database& db, const id_type& id)
  {
    using namespace pgsql;

    ODB_POTENTIALLY_UNUSED (db);

    pgsql::connection& conn (
      pgsql::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    id_image_type& i (sts.id_image ());
    init (i, id);

    binding& idb (sts.id_image_binding ());
    if (i.version != sts.id_image_version () || idb.version == 0)
    {
      bind (idb.bind, i);
      sts.id_image_version (i.version);
      idb.version++;
    }

    if (sts.erase_statement ().execute () != 1)
      throw object_not_persistent ();

    pointer_cache_traits::erase (db, id);
  }

  access::object_traits_impl< ::AccountInfo, id_pgsql >::pointer_type
  access::object_traits_impl< ::AccountInfo, id_pgsql >::
  find (database& db, const id_type& id)
  {
    using namespace pgsql;

    {
      pointer_type p (pointer_cache_traits::find (db, id));

      if (!pointer_traits::null_ptr (p))
        return p;
    }

    pgsql::connection& conn (
      pgsql::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    statements_type::auto_lock l (sts);

    if (l.locked ())
    {
      if (!find_ (sts, &id))
        return pointer_type ();
    }

    pointer_type p (
      access::object_factory<object_type, pointer_type>::create ());
    pointer_traits::guard pg (p);

    pointer_cache_traits::insert_guard ig (
      pointer_cache_traits::insert (db, id, p));

    object_type& obj (pointer_traits::get_ref (p));

    if (l.locked ())
    {
      select_statement& st (sts.find_statement ());
      ODB_POTENTIALLY_UNUSED (st);

      callback (db, obj, callback_event::pre_load);
      init (obj, sts.image (), &db);
      load_ (sts, obj, false);
      sts.load_delayed (0);
      l.unlock ();
      callback (db, obj, callback_event::post_load);
      pointer_cache_traits::load (ig.position ());
    }
    else
      sts.delay_load (id, obj, ig.position ());

    ig.release ();
    pg.release ();
    return p;
  }

  bool access::object_traits_impl< ::AccountInfo, id_pgsql >::
  find (database& db, const id_type& id, object_type& obj)
  {
    using namespace pgsql;

    pgsql::connection& conn (
      pgsql::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    statements_type::auto_lock l (sts);

    if (!find_ (sts, &id))
      return false;

    select_statement& st (sts.find_statement ());
    ODB_POTENTIALLY_UNUSED (st);

    reference_cache_traits::position_type pos (
      reference_cache_traits::insert (db, id, obj));
    reference_cache_traits::insert_guard ig (pos);

    callback (db, obj, callback_event::pre_load);
    init (obj, sts.image (), &db);
    load_ (sts, obj, false);
    sts.load_delayed (0);
    l.unlock ();
    callback (db, obj, callback_event::post_load);
    reference_cache_traits::load (pos);
    ig.release ();
    return true;
  }

  bool access::object_traits_impl< ::AccountInfo, id_pgsql >::
  reload (database& db, object_type& obj)
  {
    using namespace pgsql;

    pgsql::connection& conn (
      pgsql::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    statements_type::auto_lock l (sts);

    const id_type& id  (
      obj.login_);

    if (!find_ (sts, &id))
      return false;

    select_statement& st (sts.find_statement ());
    ODB_POTENTIALLY_UNUSED (st);

    callback (db, obj, callback_event::pre_load);
    init (obj, sts.image (), &db);
    load_ (sts, obj, true);
    sts.load_delayed (0);
    l.unlock ();
    callback (db, obj, callback_event::post_load);
    return true;
  }

  bool access::object_traits_impl< ::AccountInfo, id_pgsql >::
  find_ (statements_type& sts,
         const id_type* id)
  {
    using namespace pgsql;

    id_image_type& i (sts.id_image ());
    init (i, *id);

    binding& idb (sts.id_image_binding ());
    if (i.version != sts.id_image_version () || idb.version == 0)
    {
      bind (idb.bind, i);
      sts.id_image_version (i.version);
      idb.version++;
    }

    image_type& im (sts.image ());
    binding& imb (sts.select_image_binding ());

    if (im.version != sts.select_image_version () ||
        imb.version == 0)
    {
      bind (imb.bind, im, statement_select);
      sts.select_image_version (im.version);
      imb.version++;
    }

    select_statement& st (sts.find_statement ());

    st.execute ();
    auto_result ar (st);
    select_statement::result r (st.fetch ());

    if (r == select_statement::truncated)
    {
      if (grow (im, sts.select_image_truncated ()))
        im.version++;

      if (im.version != sts.select_image_version ())
      {
        bind (imb.bind, im, statement_select);
        sts.select_image_version (im.version);
        imb.version++;
        st.refetch ();
      }
    }

    return r != select_statement::no_data;
  }

  result< access::object_traits_impl< ::AccountInfo, id_pgsql >::object_type >
  access::object_traits_impl< ::AccountInfo, id_pgsql >::
  query (database&, const query_base_type& q)
  {
    using namespace pgsql;
    using odb::details::shared;
    using odb::details::shared_ptr;

    pgsql::connection& conn (
      pgsql::transaction::current ().connection ());

    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    image_type& im (sts.image ());
    binding& imb (sts.select_image_binding ());

    if (im.version != sts.select_image_version () ||
        imb.version == 0)
    {
      bind (imb.bind, im, statement_select);
      sts.select_image_version (im.version);
      imb.version++;
    }

    std::string text (query_statement);
    if (!q.empty ())
    {
      text += " ";
      text += q.clause ();
    }

    q.init_parameters ();
    shared_ptr<select_statement> st (
      new (shared) select_statement (
        sts.connection (),
        query_statement_name,
        text,
        false,
        true,
        q.parameter_types (),
        q.parameter_count (),
        q.parameters_binding (),
        imb));

    st->execute ();
    st->deallocate ();

    shared_ptr< odb::object_result_impl<object_type> > r (
      new (shared) pgsql::object_result_impl<object_type> (
        q, st, sts, 0));

    return result<object_type> (r);
  }

  unsigned long long access::object_traits_impl< ::AccountInfo, id_pgsql >::
  erase_query (database&, const query_base_type& q)
  {
    using namespace pgsql;

    pgsql::connection& conn (
      pgsql::transaction::current ().connection ());

    std::string text (erase_query_statement);
    if (!q.empty ())
    {
      text += ' ';
      text += q.clause ();
    }

    q.init_parameters ();
    delete_statement st (
      conn,
      erase_query_statement_name,
      text,
      q.parameter_types (),
      q.parameter_count (),
      q.parameters_binding ());

    return st.execute ();
  }
}

#include <odb/post.hxx>
