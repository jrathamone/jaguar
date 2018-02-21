//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "JaguarTestApp.h"
#include "JaguarApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

template <>
InputParameters
validParams<JaguarTestApp>()
{
  InputParameters params = validParams<JaguarApp>();
  return params;
}

JaguarTestApp::JaguarTestApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  JaguarApp::registerObjectDepends(_factory);
  JaguarApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  JaguarApp::associateSyntaxDepends(_syntax, _action_factory);
  JaguarApp::associateSyntax(_syntax, _action_factory);

  Moose::registerExecFlags(_factory);
  ModulesApp::registerExecFlags(_factory);
  JaguarApp::registerExecFlags(_factory);

  bool use_test_objs = getParam<bool>("allow_test_objects");
  if (use_test_objs)
  {
    JaguarTestApp::registerObjects(_factory);
    JaguarTestApp::associateSyntax(_syntax, _action_factory);
    JaguarTestApp::registerExecFlags(_factory);
  }
}

JaguarTestApp::~JaguarTestApp() {}

void
JaguarTestApp::registerApps()
{
  registerApp(JaguarApp);
  registerApp(JaguarTestApp);
}

void
JaguarTestApp::registerObjects(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new test objects here! */
}

void
JaguarTestApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
  /* Uncomment Syntax and ActionFactory parameters and register your new test objects here! */
}

void
JaguarTestApp::registerExecFlags(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new execute flags here! */
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
JaguarTestApp__registerApps()
{
  JaguarTestApp::registerApps();
}

// External entry point for dynamic object registration
extern "C" void
JaguarTestApp__registerObjects(Factory & factory)
{
  JaguarTestApp::registerObjects(factory);
}

// External entry point for dynamic syntax association
extern "C" void
JaguarTestApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  JaguarTestApp::associateSyntax(syntax, action_factory);
}

// External entry point for dynamic execute flag loading
extern "C" void
JaguarTestApp__registerExecFlags(Factory & factory)
{
  JaguarTestApp::registerExecFlags(factory);
}
