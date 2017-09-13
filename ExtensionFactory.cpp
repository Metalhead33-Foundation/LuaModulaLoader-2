#include "ExtensionFactory.hpp"

ExtensionFactory::ExtensionFactory()
{
	;
}
void ExtensionFactory::registerFramework(const char* a,createExtensionFrameworkA b)
{
	registry[a] = b;
}
ExtensionFactory::sExtensionFactory ExtensionFactory::getSingleton()
{
	if(!singleton) singleton = sExtensionFactory(new ExtensionFactory());
	return singleton;
}
