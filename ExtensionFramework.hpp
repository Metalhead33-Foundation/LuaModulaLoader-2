#ifndef EXTENSIONFRAMEWORK_HPP
#define EXTENSIONFRAMEWORK_HPP
#include <lua.hpp>
#include <string>
#include <vector>

typedef std::vector<luaL_Reg> luaFunctionVector;
typedef luaFunctionVector::iterator luaFunctionIterator;

class ExtensionFramework
{
private:
	std::string tableName;
	std::string metaTableName;
	luaFunctionVector fTable;
public:
	ExtensionFramework();
	void registerFunctions(lua_State *L);
	std::string& getTableName();
	std::string& getMetaTableName();
	void setTableName(std::string& setto);
	void setMetaTableName(std::string& setto);

	void uploadFunction(luaL_Reg& reg);
	void uploadFunction(const char* name, lua_CFunction func);
	void uploadFunction(const std::string& name, lua_CFunction func);
};

#endif // EXTENSIONFRAMEWORK_HPP
