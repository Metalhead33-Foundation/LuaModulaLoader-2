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
	std::string tableName;
	std::string metaTableName;
	luaFunctionVector fTable;
public:
	ExtensionFramework(std::string& settable, std::string& setmeta);
	void registerFunctions(lua_State *L);
	const std::string& getTableName() const;
	const std::string& getMetaTableName() const;
	void setTableName(std::string& setto);
	void setMetaTableName(std::string& setto);

	void uploadFunction(luaL_Reg& reg);
	void uploadFunction(const char* name, lua_CFunction func);
	void uploadFunction(const std::string& name, lua_CFunction func);
};
typedef std::shared_ptr<ExtensionFramework> sExtensionFramework;

#endif // EXTENSIONFRAMEWORK_HPP
