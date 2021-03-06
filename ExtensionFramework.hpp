#ifndef EXTENSIONFRAMEWORK_HPP
#define EXTENSIONFRAMEWORK_HPP
#include <lua.hpp>
#include <string>
#include <vector>
#include <memory>

typedef std::vector<luaL_Reg> luaFunctionVector;
typedef luaFunctionVector::iterator luaFunctionIterator;

class ExtensionFramework
{
private:
	const char* tableName;
	const char* metaTableName;
	luaFunctionVector fTable;
public:
	ExtensionFramework(const std::string& settable, const std::string& setmeta);
	ExtensionFramework(const char* settable, const char* setmeta);
	void registerFunctions(lua_State *L);
	const char* getTableName() const;
	const char* getMetaTableName() const;
	void setTableName(const char* setto);
	void setMetaTableName(const char* setto);

	void uploadFunction(luaL_Reg& reg);
	void uploadFunction(const char* name, lua_CFunction func);
	void uploadFunction(const std::string& name, lua_CFunction func);

	virtual void getReady() = 0;
};
typedef std::shared_ptr<ExtensionFramework> sExtensionFramework;
typedef ExtensionFramework* (*createExtensionFramework)(void);

#endif // EXTENSIONFRAMEWORK_HPP
