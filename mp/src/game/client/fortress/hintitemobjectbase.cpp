#include "cbase.h"
#include "hintitemobjectbase.h"
#include <KeyValues.h>
#ifdef IMPLEMENT_ME
#include "c_obj_resourcepump.h"
#endif
#include "c_func_resource.h"

CHintItemObjectBase::CHintItemObjectBase( vgui::Panel *parent, const char *panelName )
: BaseClass( parent, panelName )
{
	SetObjectType( "" );
}

void CHintItemObjectBase::ParseItem( KeyValues *pKeyValues )
{
	BaseClass::ParseItem( pKeyValues );
	
	const char *type = pKeyValues->GetString( "type", "" );
	if ( type )
	{
		SetObjectType( type );
	}
}

bool CHintItemObjectBase::IsObjectOfType( C_BaseEntity *object )
{
	if ( !stricmp( GetObjectType(), "Resource Zone" ) )
		return dynamic_cast< C_ResourceZone *>( object ) ? true : false;
#ifdef IMPLEMENT_ME
	else if ( !stricmp( GetObjectType(), "Resource Pump" ) )
		return dynamic_cast< C_ObjectResourcePump * >( object) ? true : false;
	else if ( !stricmp( GetObjectType(), "BaseObject" ) )
		return dynamic_cast< C_BaseObject * >( object) ? true : false;
#endif
	
	return false;
}

void CHintItemObjectBase::SetObjectType( const char *type )
{
	Q_strncpy( m_szObjectType, type, MAX_OBJECT_TYPE );
}

const char *CHintItemObjectBase::GetObjectType( void )
{
	return m_szObjectType;
}