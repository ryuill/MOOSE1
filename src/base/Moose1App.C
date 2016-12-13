#include "Moose1App.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template<>
InputParameters validParams<Moose1App>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

Moose1App::Moose1App(InputParameters parameters) :
    MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  Moose1App::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  Moose1App::associateSyntax(_syntax, _action_factory);
}

Moose1App::~Moose1App()
{
}

// External entry point for dynamic application loading
extern "C" void Moose1App__registerApps() { Moose1App::registerApps(); }
void
Moose1App::registerApps()
{
  registerApp(Moose1App);
}

// External entry point for dynamic object registration
extern "C" void Moose1App__registerObjects(Factory & factory) { Moose1App::registerObjects(factory); }
void
Moose1App::registerObjects(Factory & factory)
{
}

// External entry point for dynamic syntax association
extern "C" void Moose1App__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { Moose1App::associateSyntax(syntax, action_factory); }
void
Moose1App::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}
