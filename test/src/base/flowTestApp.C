//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "flowTestApp.h"
#include "flowApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

template <>
InputParameters
validParams<flowTestApp>()
{
  InputParameters params = validParams<flowApp>();
  return params;
}

flowTestApp::flowTestApp(InputParameters parameters) : MooseApp(parameters)
{
  flowTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

flowTestApp::~flowTestApp() {}

void
flowTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  flowApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"flowTestApp"});
    Registry::registerActionsTo(af, {"flowTestApp"});
  }
}

void
flowTestApp::registerApps()
{
  registerApp(flowApp);
  registerApp(flowTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
flowTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  flowTestApp::registerAll(f, af, s);
}
extern "C" void
flowTestApp__registerApps()
{
  flowTestApp::registerApps();
}
