#include "ExtensionFactory.hpp"

ExtensionFactory::sExtensionFactory ExtensionFactory::singleton = 0;

ExtensionFactory::ExtensionFactory()
{
	prepared = false;
	registered = false;
}
ExtensionFactory::~ExtensionFactory()
{
	extReg.clear();
}
void ExtensionFactory::registerFramework(const char* a,createExtensionFramework b)
{
	extReg[a] = b;
}
void ExtensionFactory::registerFramework(const char* a, void* lib)
{
	extReg[a] = reinterpret_cast<createExtensionFramework>(dlsym(lib,"CREATE_MODULE"));
}
void ExtensionFactory::registerFramework(const char* a, const char* libpath)
{
	registerFramework(a, dlopen(libpath,RTLD_NOW | RTLD_LOCAL));
}
ExtensionFactory::sExtensionFactory ExtensionFactory::getSingleton()
{
	if(!singleton) singleton = sExtensionFactory(new ExtensionFactory());
	return singleton;
}
void ExtensionFactory::prepareLibraries(void)
{
	if(prepared || registered) return;
	for(extensionIterator it = extReg.begin(); it != extReg.end();++it)
	{
		modReg[it->first] = it->second();
	}
	extReg.clear();
	prepared = true;
}
void ExtensionFactory::registerLibraries(lua_State* L)
{
	if(registered) return;
	if(!prepared) prepareLibraries();
	for(moduleIterator it = modReg.begin(); it != modReg.end(); ++it)
	{
		it->second->registerFunctions(L);
	}
}
