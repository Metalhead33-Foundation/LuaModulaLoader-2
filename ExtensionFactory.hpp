#ifndef EXTENSIONFACTORY_HPP
#define EXTENSIONFACTORY_HPP
#include "ExtensionFramework.hpp"
#include <map>

typedef std::map<const char*,createExtensionFrameworkA> extensionRegistry;
typedef extensionRegistry::iterator extensionIterator;

class ExtensionFactory
{
public:
	typedef std::shared_ptr<ExtensionFactory> sExtensionFactory;
private:
	ExtensionFactory();
	static sExtensionFactory singleton;
protected:
	extensionRegistry registry;
public:
	void registerFramework(const char* a,createExtensionFrameworkA b);
	static sExtensionFactory getSingleton();
};

#endif // EXTENSIONFACTORY_HPP
