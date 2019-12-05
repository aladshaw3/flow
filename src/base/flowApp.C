#include "flowApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template <>
InputParameters
validParams<flowApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

flowApp::flowApp(InputParameters parameters) : MooseApp(parameters)
{
  flowApp::registerAll(_factory, _action_factory, _syntax);
}

flowApp::~flowApp() {}

void
flowApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAll(f, af, s);
  Registry::registerObjectsTo(f, {"flowApp"});
  Registry::registerActionsTo(af, {"flowApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
flowApp::registerApps()
{
  registerApp(flowApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
flowApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  flowApp::registerAll(f, af, s);
}
extern "C" void
flowApp__registerApps()
{
  flowApp::registerApps();
}
