#include "ExtensionFactory.hpp"

ExtensionFactory::ExtensionFactory(std::string& settable, std::string& setmeta)
	: module(settable,setmeta)
{
	getReady();
}
const ExtensionFramework& ExtensionFactory::getModule() const
{
	return module;
}
