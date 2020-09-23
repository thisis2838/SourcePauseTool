#include "..\..\stdafx.hpp"
#pragma once

#include <SPTLib\IHookableNameFilter.hpp>

#include <SDK\hl_movedata.h>
#include "..\..\utils\patterncontainer.hpp"
#include "engine\iserverplugin.h"

using std::ptrdiff_t;
using std::size_t;
using std::uintptr_t;

typedef bool(__fastcall* _CheckJumpButton)(void* thisptr, int edx);
typedef void(__fastcall* _FinishGravity)(void* thisptr, int edx);
typedef void(__fastcall* _PlayerRunCommand)(void* thisptr, int edx, void* ucmd, void* moveHelper);
typedef int(__fastcall* _CheckStuck)(void* thisptr, int edx);
typedef void(__fastcall* _AirAccelerate)(void* thisptr, int edx, Vector* wishdir, float wishspeed, float accel);
typedef void(__fastcall* _ProcessMovement)(void* thisptr, int edx, void* pPlayer, void* pMove);
typedef void(__fastcall* _SnapEyeAngles)(void* thisptr, int edx, const QAngle& viewAngles);
typedef float(__fastcall* _FirePortal)(void* thisptr, int edx, bool bPortal2, Vector* pVector, bool bTest);
typedef float(__fastcall* _TraceFirePortal)(void* thisptr,
                                            int edx,
                                            bool bPortal2,
                                            const Vector& vTraceStart,
                                            const Vector& vDirection,
                                            trace_t& tr,
                                            Vector& vFinalPosition,
                                            QAngle& qFinalAngles,
                                            int iPlacedBy,
                                            bool bTest);
typedef void*(__fastcall* _GetActiveWeapon)(void* thisptr);
typedef void(__fastcall* _SlidingAndOtherStuff)(void* thisptr, int edx, void* a, void* b);
typedef CBaseEntity*(__cdecl* _CreateEntityByName)(const char* name, int forceEdictIndex);
typedef int(__fastcall* _CRestore__ReadAll)(void* thisptr, int edx, void* pLeafObject, datamap_t* pLeafMap);
typedef int(__fastcall* _CRestore__DoReadAll)(void* thisptr,
                                              int edx,
                                              void* pLeafObject,
                                              datamap_t* pLeafMap,
                                              datamap_t* pCurMap);
typedef int(__cdecl* _DispatchSpawn)(void* pEntity);
typedef string_t(__cdecl* _AllocPooledString)(const char* pszValue, int trash);
typedef void(__fastcall* _CGameMovement__TracePlayerBBox)(void* thisptr,
                                                          int edx,
                                                          const Vector& start,
                                                          const Vector& end,
                                                          unsigned int fMask,
                                                          int collisionGroup,
                                                          trace_t& pm);
typedef void(__fastcall* _CPortalGameMovement__TracePlayerBBox)(void* thisptr,
                                                                int edx,
                                                                const Vector& start,
                                                                const Vector& end,
                                                                unsigned int fMask,
                                                                int collisionGroup,
                                                                trace_t& pm);
typedef const Vector&(__fastcall* _CGameMovement__GetPlayerMaxs)(void* thisptr, int edx);
typedef const Vector&(__fastcall* _CGameMovement__GetPlayerMins)(void* thisptr, int edx);
typedef void(__cdecl* _TracePlayerBBoxForGround)(const Vector& start,
                                                 const Vector& end,
                                                 const Vector& mins,
                                                 const Vector& maxs,
                                                 IHandleEntity* player,
                                                 unsigned int fMask,
                                                 int collisionGroup,
                                                 trace_t& pm);
typedef void(__cdecl* _TracePlayerBBoxForGround2)(const Vector& start,
                                                  const Vector& end,
                                                  const Vector& mins,
                                                  const Vector& maxs,
                                                  IHandleEntity* player,
                                                  unsigned int fMask,
                                                  int collisionGroup,
                                                  trace_t& pm);

class ServerDLL : public IHookableNameFilter
{
public:
	ServerDLL() : IHookableNameFilter({L"server.dll"}){};
	virtual void Hook(const std::wstring& moduleName,
	                  void* moduleHandle,
	                  void* moduleBase,
	                  size_t moduleLength,
	                  bool needToIntercept);
	virtual void Unhook();
	virtual void Clear();

	static bool __fastcall HOOKED_CheckJumpButton(void* thisptr, int edx);
	static void __fastcall HOOKED_FinishGravity(void* thisptr, int edx);
	static void __fastcall HOOKED_PlayerRunCommand(void* thisptr, int edx, void* ucmd, void* moveHelper);
	static int __fastcall HOOKED_CheckStuck(void* thisptr, int edx);
	static void __fastcall HOOKED_AirAccelerate(void* thisptr,
	                                            int edx,
	                                            Vector* wishdir,
	                                            float wishspeed,
	                                            float accel);
	static void __fastcall HOOKED_ProcessMovement(void* thisptr, int edx, void* pPlayer, void* pMove);
	static float __fastcall HOOKED_TraceFirePortal(void* thisptr,
	                                               int edx,
	                                               bool bPortal2,
	                                               const Vector& vTraceStart,
	                                               const Vector& vDirection,
	                                               trace_t& tr,
	                                               Vector& vFinalPosition,
	                                               QAngle& qFinalAngles,
	                                               int iPlacedBy,
	                                               bool bTest);
	static void __fastcall HOOKED_SlidingAndOtherStuff(void* thisptr, int edx, void* a, void* b);
	static int __fastcall HOOKED_CRestore__ReadAll(void* thisptr, int edx, void* pLeafObject, datamap_t* pLeafMap);
	static int __fastcall HOOKED_CRestore__DoReadAll(void* thisptr,
	                                                 int edx,
	                                                 void* pLeafObject,
	                                                 datamap_t* pLeafMap,
	                                                 datamap_t* pCurMap);
	static int __cdecl HOOKED_DispatchSpawn(void* pEntity);
	static void HOOKED_MiddleOfSlidingFunction();
	static const Vector& __fastcall HOOKED_CGameMovement__GetPlayerMaxs(void* thisptr, int edx);
	static const Vector& __fastcall HOOKED_CGameMovement__GetPlayerMins(void* thisptr, int edx);

	void TracePlayerBBox(const Vector& start,
	                     const Vector& end,
	                     const Vector& mins,
	                     const Vector& maxs,
	                     unsigned int fMask,
	                     int collisionGroup,
	                     trace_t& pm);
	bool __fastcall HOOKED_CheckJumpButton_Func(void* thisptr, int edx);
	void __fastcall HOOKED_FinishGravity_Func(void* thisptr, int edx);
	void __fastcall HOOKED_PlayerRunCommand_Func(void* thisptr, int edx, void* ucmd, void* moveHelper);
	int __fastcall HOOKED_CheckStuck_Func(void* thisptr, int edx);
	void __fastcall HOOKED_AirAccelerate_Func(void* thisptr,
	                                          int edx,
	                                          Vector* wishdir,
	                                          float wishspeed,
	                                          float accel);
	void __fastcall HOOKED_ProcessMovement_Func(void* thisptr, int edx, void* pPlayer, void* pMove);
	float __fastcall HOOKED_TraceFirePortal_Func(void* thisptr,
	                                             int edx,
	                                             bool bPortal2,
	                                             const Vector& vTraceStart,
	                                             const Vector& vDirection,
	                                             trace_t& tr,
	                                             Vector& vFinalPosition,
	                                             QAngle& qFinalAngles,
	                                             int iPlacedBy,
	                                             bool bTest);
	void __fastcall HOOKED_SlidingAndOtherStuff_Func(void* thisptr, int edx, void* a, void* b);
	void HOOKED_MiddleOfSlidingFunction_Func();
	static void HOOKED_BMS_WallclimbCheck();
	void HOOKED_BMS_WallclimbCheck_Func();
	bool CanTracePlayerBBox();

	void StartTimer()
	{
		timerRunning = true;
	}
	void StopTimer()
	{
		timerRunning = false;
	}
	void ResetTimer()
	{
		ticksPassed = 0;
		timerRunning = false;
	}
	unsigned int GetTicksPassed() const
	{
		return ticksPassed;
	}
	int GetPlayerPhysicsFlags() const;
	int GetPlayerMoveType() const;
	int GetPlayerMoveCollide() const;
	int GetPlayerCollisionGroup() const;
	int GetEnviromentPortalHandle() const;

	_SnapEyeAngles SnapEyeAngles;
	_FirePortal FirePortal;
	double lastTraceFirePortalDistanceSq;
	Vector lastTraceFirePortalNormal;
	_GetActiveWeapon GetActiveWeapon;
	_CreateEntityByName ORIG_CreateEntityByName;
	int* m_hPortalEnvironmentOffsetPtr;
	_CRestore__ReadAll ORIG_CRestore__ReadAll;
	_CRestore__DoReadAll ORIG_CRestore__DoReadAll;
	_DispatchSpawn ORIG_DispatchSpawn;
	_AllocPooledString ORIG_AllocPooledString;
	_CGameMovement__GetPlayerMins ORIG_CGameMovement__GetPlayerMins;
	_CGameMovement__GetPlayerMaxs ORIG_CGameMovement__GetPlayerMaxs;
	_CGameMovement__TracePlayerBBox ORIG_CGameMovement__TracePlayerBBox;
	_CPortalGameMovement__TracePlayerBBox ORIG_CPortalGameMovement__TracePlayerBBox;
	_TracePlayerBBoxForGround ORIG_TracePlayerBBoxForGround;
	_TracePlayerBBoxForGround2 ORIG_TracePlayerBBoxForGround2;
	Gallant::Signal0<void> JumpSignal;
	bool overrideMinMax;
	Vector _mins;
	Vector _maxs;

protected:
	PatternContainer patternContainer;
	_CheckJumpButton ORIG_CheckJumpButton;
	_FinishGravity ORIG_FinishGravity;
	_PlayerRunCommand ORIG_PlayerRunCommand;
	_CheckStuck ORIG_CheckStuck;
	_AirAccelerate ORIG_AirAccelerate;
	_ProcessMovement ORIG_ProcessMovement;
	_TraceFirePortal ORIG_TraceFirePortal;
	_SlidingAndOtherStuff ORIG_SlidingAndOtherStuff;
	void* ORIG_MiddleOfSlidingFunction;

	void* ORIG_BMS_WallclimbCheck;
	uintptr_t BMS_WallclimbCheck_JumpTo1;
	uintptr_t BMS_WallclimbCheck_JumpTo2;
	bool ORIG_BMS_WallclimbCheck_Jump;

protected:
	ptrdiff_t off1M_nOldButtons;
	ptrdiff_t off2M_nOldButtons;
	bool cantJumpNextTime;
	bool insideCheckJumpButton;
	ptrdiff_t off1M_bDucked;
	ptrdiff_t off2M_bDucked;
	ptrdiff_t offM_vecAbsVelocity;
	ptrdiff_t offM_afPhysicsFlags;
	ptrdiff_t offM_moveType;
	ptrdiff_t offM_moveCollide;
	ptrdiff_t offM_collisionGroup;

	unsigned ticksPassed;
	bool timerRunning;

	bool sliding;
	bool wasSliding;
};
