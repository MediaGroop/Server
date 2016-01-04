// file      : odb/tracer.cxx
// copyright : Copyright (c) 2009-2013 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#include <iostream>

#include <odb/tracer.hxx>
#include <odb/statement.hxx>

using namespace std;

namespace odb
{
  //
  // tracer
  //

  tracer::
  ~tracer ()
  {
  }

  void tracer::
  prepare (connection&, const statement&)
  {
  }

  void tracer::
  execute (connection& c, const statement& s)
  {
    execute (c, s.text ());
  }

  void tracer::
  deallocate (connection&, const statement&)
  {
  }

  //
  // stderr_tracer
  //

  class stderr_tracer_type: public tracer
  {
    virtual void
    execute (connection&, const char* statement);

    // Override the other version to get rid of a Sun CC warning.
    //
    virtual void
    execute (connection&, const statement&);
  };

  void stderr_tracer_type::
  execute (connection&, const char* s)
  {
    cerr << s << endl;
  }

  void stderr_tracer_type::
  execute (connection& c, const statement& s)
  {
    execute (c, s.text ());
  }

  static stderr_tracer_type stderr_tracer_;
  tracer& stderr_tracer = stderr_tracer_;
}
