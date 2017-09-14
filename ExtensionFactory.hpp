#ifndef EXTENSIONFACTORY_HPP
#define EXTENSIONFACTORY_HPP
#include "ExtensionFramework.hpp"
#include <dlfcn.h>
#include <map>
#include <stdexcept>

typedef std::map<const char*,createExtensionFramework> extensionRegistry;
typedef extensionRegistry::iterator extensionIterator;
typedef std::map<const char*,ExtensionFramework*> moduleRegistry;
typedef moduleRegistry::iterator moduleIterator;

class ExtensionFactory
{
public:
	typedef std::shared_ptr<ExtensionFactory> sExtensionFactory;
private:
	ExtensionFactory();
	static sExtensionFactory singleton;
	bool prepared;
	bool registered;
protected:
	extensionRegistry extReg;
	moduleRegistry modReg;
public:
	void registerFramework(const char* a, createExtensionFramework b);
	void registerFramework(const char* a, void* lib);
	void registerFramework(const char* a, const char* libpath);
	void prepareLibraries(void);
	void registerLibraries(lua_State* L);
	static sExtensionFactory getSingleton();
	~ExtensionFactory();
};

#endif // EXTENSIONFACTORY_HPP
