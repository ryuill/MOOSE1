#ifndef MOOSE1APP_H
#define MOOSE1APP_H

#include "MooseApp.h"

class Moose1App;

template<>
InputParameters validParams<Moose1App>();

class Moose1App : public MooseApp
{
public:
  Moose1App(InputParameters parameters);
  virtual ~Moose1App();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* MOOSE1APP_H */
