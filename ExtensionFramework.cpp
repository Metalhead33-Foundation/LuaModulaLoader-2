#include "ExtensionFramework.hpp"

ExtensionFramework::ExtensionFramework(const std::string& settable, const std::string& setmeta)
{
	tableName = settable.c_str();
	metaTableName = setmeta.c_str();
}
ExtensionFramework::ExtensionFramework(const char* settable, const char* setmeta)
{
	tableName = settable;
	metaTableName = setmeta;
}
void ExtensionFramework::registerFunctions(lua_State *L)
{
	getReady();
	if(fTable[fTable.size()-1].func && fTable[fTable.size()-1].name)
	{
		fTable.push_back( { NULL, NULL} );
	}
	luaL_newmetatable(L, metaTableName);
	luaL_register(L, NULL, fTable.data());
	lua_pushvalue(L, -1);
	lua_setfield(L, -1, metaTableName);
	lua_setglobal(L, tableName);
}
const char* ExtensionFramework::getTableName() const
{
	return tableName;
}
const char* ExtensionFramework::getMetaTableName() const
{
	return metaTableName;
}
void ExtensionFramework::setTableName(const char* setto)
{
	tableName = setto;
}
void ExtensionFramework::setMetaTableName(const char* setto)
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
