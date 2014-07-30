//========= Copyright � 1996-2002, Valve LLC, All rights reserved. ============
//
// Purpose: Auto Repair
//
// $NoKeywords: $
//=============================================================================

#ifndef TF_GAMEMOVEMENT_CHOOSER_H
#define TF_GAMEMOVEMENT_CHOOSER_H
#ifdef _WIN32
#pragma once
#endif

#include "UtlVector.h"
#include "IGameMovement.h"
#include "tf_gamemovement.h"
#ifdef IMPLEMENT_ME
#include "tf_gamemovement_recon.h"
#include "tf_gamemovement_commando.h"
#include "tf_gamemovement_medic.h"
#include "tf_gamemovement_defender.h"
#include "tf_gamemovement_sniper.h"
#include "tf_gamemovement_support.h"
#include "tf_gamemovement_escort.h"
#include "tf_gamemovement_sapper.h"
#include "tf_gamemovement_infiltrator.h"
#include "tf_gamemovement_pyro.h"
#endif

//=============================================================================
//
// Team Fortess Game Movement Chooser
//
class CTFGameMovementChooser : public CGameMovement	// Was IGameMovement. ~hogsy
{
public:

	CTFGameMovementChooser();

	// Process the current movement command
	virtual void ProcessMovement( CBasePlayer *pPlayer, CMoveData *pMoveData );		

	// Allows other parts of the engine to find out the normal and ducked player bbox sizes
	virtual Vector GetPlayerMins( bool ducked ) const;
	virtual Vector GetPlayerMaxs( bool ducked ) const;
	virtual Vector GetPlayerViewOffset( bool ducked ) const;

protected:

	// Cache the current class id.
	int								m_nClassID;

#ifdef IMPLEMENT_ME
	// Create the class specific movement singletons.
	CTFGameMovementRecon			m_ReconMovement;
	CTFGameMovementCommando			m_CommandoMovement;
	CTFGameMovementMedic			m_MedicMovement;
	CTFGameMovementDefender			m_DefenderMovement;
	CTFGameMovementSniper			m_SniperMovement;
	CTFGameMovementSupport			m_SupportMovement;
	CTFGameMovementEscort			m_EscortMovement;
	CTFGameMovementSapper			m_SapperMovement;
	CTFGameMovementInfiltrator		m_InfiltratorMovement;
	CTFGameMovementPyro				m_PyroMovement;
#endif

	// Vector of class specific movements (for quick addressing).
	CUtlVector<CTFGameMovement*>	m_Movements;
};

extern IGameMovement *g_pGameMovement;

#endif // TF_GAMEMOVEMENT_CHOOSER_H