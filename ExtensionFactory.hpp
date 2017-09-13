#ifndef EXTENSIONFACTORY_HPP
#define EXTENSIONFACTORY_HPP
#include "ExtensionFramework.hpp"

class ExtensionFactory
{
protected:
	ExtensionFramework module;
public:
	ExtensionFactory(std::string& settable, std::string& setmeta);
	const ExtensionFramework& getModule() const;
	virtual void getReady() = 0;
};

#endif // EXTENSIONFACTORY_HPP
