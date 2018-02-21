#include "JaguarApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template <>
InputParameters
validParams<JaguarApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

JaguarApp::JaguarApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  JaguarApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  JaguarApp::associateSyntax(_syntax, _action_factory);

  Moose::registerExecFlags(_factory);
  ModulesApp::registerExecFlags(_factory);
  JaguarApp::registerExecFlags(_factory);
}

JaguarApp::~JaguarApp() {}

void
JaguarApp::registerApps()
{
  registerApp(JaguarApp);
}

void
JaguarApp::registerObjects(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new production objects here! */
}

void
JaguarApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
  /* Uncomment Syntax and ActionFactory parameters and register your new production objects here! */
}

void
JaguarApp::registerObjectDepends(Factory & /*factory*/)
{
}

void
JaguarApp::associateSyntaxDepends(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}

void
JaguarApp::registerExecFlags(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new execution flags here! */
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
JaguarApp__registerApps()
{
  JaguarApp::registerApps();
}

extern "C" void
JaguarApp__registerObjects(Factory & factory)
{
  JaguarApp::registerObjects(factory);
}

extern "C" void
JaguarApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  JaguarApp::associateSyntax(syntax, action_factory);
}

extern "C" void
JaguarApp__registerExecFlags(Factory & factory)
{
  JaguarApp::registerExecFlags(factory);
}
