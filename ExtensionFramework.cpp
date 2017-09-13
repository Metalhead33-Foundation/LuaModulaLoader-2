#include "ExtensionFramework.hpp"

ExtensionFramework::ExtensionFramework(std::string& settable, std::string& setmeta, lua_State *L)
{
	tableName = settable;
	metaTableName = setmeta;
	getReady();
	registerFunctions(L);
}
void ExtensionFramework::registerFunctions(lua_State *L)
{
	if(fTable[fTable.size()-1].func && fTable[fTable.size()-1].name)
	{
		fTable.push_back( { NULL, NULL} );
	}
	luaL_newmetatable(L, metaTableName.c_str());
	luaL_register(L, NULL, fTable.data());
	lua_pushvalue(L, -1);
	lua_setfield(L, -1, metaTableName.c_str());
	lua_setglobal(L, tableName.c_str());
}
const std::string& ExtensionFramework::getTableName() const
{
	return tableName;
}
const std::string& ExtensionFramework::getMetaTableName() const
{
	return metaTableName;
}
void ExtensionFramework::setTableName(std::string& setto)
{
	tableName = setto;
}
void ExtensionFramework::setMetaTableName(std::string& setto)
{
	metaTableName = setto;
}
void ExtensionFramework::uploadFunction(luaL_Reg& reg)
{
	fTable.push_back(reg);
}
void ExtensionFramework::uploadFunction(const char* name, lua_CFunction func)
{
	fTable.push_back( {name,func} );
}
void ExtensionFramework::uploadFunction(const std::string& name, lua_CFunction func)
{
	fTable.push_back( {name.c_str(),func} );
}
