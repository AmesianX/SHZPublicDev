#include "stdafx.h"
#include "XSpecialActionTransition.h"
#include "XMyPlayer.h"

void XSpecialActionTransChecker::Init()
{
	// 콤보테이블.xls --
	// 1타 - NA_NORMAL1
	// 2타 - NA_NORMAL2
	// 3타 - NA_NORMAL3
	// 4타 - NA_NORMAL4
	// 5타 - NA_NORMAL5
	// 후행(RMB+LMB) - NA_SUPER
	// 앞+LMB - NA_ADVANCE
	// 뒤+LMB - NA_UPPER
	// 발도 1타 - NA_SWORD_DRAWING
	// 앞구르기 - NA_DODGE_FRONT
	// 뒤구르기 - NA_DODGE_BACK
	// 옆구르기 - NA_DODGE_LEFT, NA_DODGE_RIGHT
	// 액티브 - NA_USE_TALENT__CLIENT_ONLY

	// dodge
	DefTrans_AllWeapons(SPECIAL_KEY_DODGE_FRONT,	NA_DODGE_FRONT);
	DefTrans_AllWeapons(SPECIAL_KEY_DODGE_BACK,	NA_DODGE_BACK);
	DefTrans_AllWeapons(SPECIAL_KEY_DODGE_LEFT,	NA_DODGE_LEFT);
	DefTrans_AllWeapons(SPECIAL_KEY_DODGE_RIGHT,	NA_DODGE_RIGHT);

	DefConst_AllWeapons(NA_DODGE_FRONT,	XNormalAttackTypeConstraint(TEPT_NONE, _STANCE_ALL, 0));
	DefConst_AllWeapons(NA_DODGE_BACK,	XNormalAttackTypeConstraint(TEPT_NONE, _STANCE_ALL, 0));
	DefConst_AllWeapons(NA_DODGE_LEFT,	XNormalAttackTypeConstraint(TEPT_NONE, _STANCE_ALL, 0));
	DefConst_AllWeapons(NA_DODGE_RIGHT,	XNormalAttackTypeConstraint(TEPT_NONE, _STANCE_ALL, 0));

	// 기본 공격 1타
	DefConst_AllWeapons(NA_NORMAL1,	XNormalAttackTypeConstraint(TEPT_NONE, _STANCE_BATTLE, 0));

	// 기본 공격 2타
	DefConst_AllWeapons(NA_NORMAL2,	XNormalAttackTypeConstraint(TEPT_NONE, _STANCE_BATTLE, 0));

	// 기본 공격 3타
	DefConst_AllWeapons(NA_NORMAL3,	XNormalAttackTypeConstraint(TEPT_3COMBO, _STANCE_BATTLE, 0));

	// 기본 공격 4타
	DefConst_AllWeapons(NA_NORMAL4,	XNormalAttackTypeConstraint(TEPT_3COMBO, _STANCE_BATTLE, 0));

	// 기본 공격 5타
	DefConst_AllWeapons(NA_NORMAL5,	XNormalAttackTypeConstraint(TEPT_3COMBO, _STANCE_BATTLE, 0));

	// 기본 공격 6타
	DefConst_AllWeapons(NA_NORMAL6,	XNormalAttackTypeConstraint(TEPT_3COMBO, _STANCE_BATTLE, 0));

	// SPECIAL_KEY_COUNTER_ATTACK
	DefTrans_AllWeapons(SPECIAL_KEY_COUNTER_ATTACK,	NA_COUNTER_ATTACK);
	DefConst_AllWeapons(NA_COUNTER_ATTACK,	XNormalAttackTypeConstraint(TEPT_COUNTER, _STANCE_BATTLE, 0));

	// SPECIAL_KEY_SWORD_DRAWING
	DefTrans_AllWeapons(SPECIAL_KEY_SWORD_DRAWING,	NA_SWORD_DRAWING);
	DefConst(WEAPON_1H_SLASH,	NA_SWORD_DRAWING, XNormalAttackTypeConstraint(TEPT_SWORD_DRAWING, _STANCE_NORMAL, 0));
	DefConst(WEAPON_1H_BLUNT,	NA_SWORD_DRAWING, XNormalAttackTypeConstraint(TEPT_SWORD_DRAWING, _STANCE_NORMAL, 0));
	DefConst(WEAPON_1H_PIERCE,	NA_SWORD_DRAWING, XNormalAttackTypeConstraint(TEPT_SWORD_DRAWING, _STANCE_NORMAL, 0));
	DefConst(WEAPON_TWO_HANDED, NA_SWORD_DRAWING, XNormalAttackTypeConstraint(TEPT_SWORD_DRAWING, _STANCE_NORMAL, 0));
	DefConst(WEAPON_DUAL_WIELD, NA_SWORD_DRAWING, XNormalAttackTypeConstraint(TEPT_SWORD_DRAWING, _STANCE_NORMAL, 0));
	DefConst(WEAPON_2H_BLUNT,	NA_SWORD_DRAWING, XNormalAttackTypeConstraint(TEPT_SWORD_DRAWING, _STANCE_NORMAL, 0));
	DefConst(WEAPON_DUAL_PIERCE, NA_SWORD_DRAWING, XNormalAttackTypeConstraint(TEPT_SWORD_DRAWING, _STANCE_NORMAL, 0));

	// SPECIAL_KEY_UPPER
	DefTrans_AllWeapons(SPECIAL_KEY_UPPER,	NA_UPPER);
	DefConst_AllWeapons(NA_UPPER,	XNormalAttackTypeConstraint(TEPT_UPPERCUT, _STANCE_BATTLE, 0));

	// SPECIAL_KEY_UPPERCOMBO
	DefTrans_AllWeapons(SPECIAL_KEY_UPPERCOMBO,	NA_UPPERCOMBO1);
	DefConst_AllWeapons(NA_UPPERCOMBO1,	XNormalAttackTypeConstraint(TEPT_COUNTER, _STANCE_BATTLE, 0));

	// SPECIAL_KEY_ADVANCE_ATTACK
	DefTrans_AllWeapons(SPECIAL_KEY_ADVANCE_ATTACK, NA_ADVANCE);
	DefConst_AllWeapons(NA_ADVANCE, XNormalAttackTypeConstraint(TEPT_NONE, _STANCE_BATTLE, 0));

	//SPECIAL_KEY_SUPERATTACK
	DefTrans_AllWeapons(SPECIAL_KEY_SUPERATTACK,	NA_SUPER);
	DefConst_AllWeapons(NA_SUPER,	XNormalAttackTypeConstraint(TEPT_NONE, _STANCE_BATTLE, 0));

	DefConst_AllWeapons(NA_USE_TALENT__CLIENT_ONLY,	XNormalAttackTypeConstraint(TEPT_NONE, _STANCE_ALL, 0));
	
	DefTrans_AllWeapons(SPECIAL_KEY_GUARD,	NA_GUARD__CLIENT_ONLY);
	DefConst_AllWeapons(NA_GUARD__CLIENT_ONLY,	XNormalAttackTypeConstraint(TEPT_NONE, _STANCE_BATTLE, 0));
	// 콤보 ----------------

	// 1hs -----------------------------------------------------
	DefCombo_1HS(NA_NORMAL1, NA_NORMAL2);
	DefCombo_1HS(NA_NORMAL1, NA_SUPER);
	DefCombo_1HS(NA_NORMAL1, NA_ADVANCE);
	DefCombo_1HS(NA_NORMAL1, NA_UPPER);
	DefCombo_1HS(NA_NORMAL1, NA_DODGE_FRONT);
	DefCombo_1HS(NA_NORMAL1, NA_DODGE_BACK);
	DefCombo_1HS(NA_NORMAL1, NA_DODGE_LEFT);
	DefCombo_1HS(NA_NORMAL1, NA_DODGE_RIGHT);
	DefCombo_1HS(NA_NORMAL1, NA_USE_TALENT__CLIENT_ONLY);
	DefCombo_1HS(NA_NORMAL1, NA_GUARD__CLIENT_ONLY);

	DefCombo_1HS(NA_NORMAL2, NA_NORMAL3);
	DefCombo_1HS(NA_NORMAL2, NA_UPPER);
	DefCombo_1HS(NA_NORMAL2, NA_DODGE_FRONT);
	DefCombo_1HS(NA_NORMAL2, NA_DODGE_BACK);
	DefCombo_1HS(NA_NORMAL2, NA_DODGE_LEFT);
	DefCombo_1HS(NA_NORMAL2, NA_DODGE_RIGHT);
	DefCombo_1HS(NA_NORMAL2, NA_USE_TALENT__CLIENT_ONLY);
	DefCombo_1HS(NA_NORMAL2, NA_GUARD__CLIENT_ONLY);

	DefCombo_1HS(NA_NORMAL3, NA_NORMAL4);
	DefCombo_1HS(NA_NORMAL3, NA_SUPER);
	DefCombo_1HS(NA_NORMAL3, NA_ADVANCE);
	DefCombo_1HS(NA_NORMAL3, NA_UPPER);
	DefCombo_1HS(NA_NORMAL3, NA_DODGE_FRONT);
	DefCombo_1HS(NA_NORMAL3, NA_DODGE_BACK);
	DefCombo_1HS(NA_NORMAL3, NA_DODGE_LEFT);
	DefCombo_1HS(NA_NORMAL3, NA_DODGE_RIGHT);
	DefCombo_1HS(NA_NORMAL3, NA_USE_TALENT__CLIENT_ONLY);
	DefCombo_1HS(NA_NORMAL3, NA_GUARD__CLIENT_ONLY);

	DefCombo_1HS(NA_NORMAL4, NA_NORMAL5);
	DefCombo_1HS(NA_NORMAL4, NA_UPPER);
	DefCombo_1HS(NA_NORMAL4, NA_DODGE_FRONT);
	DefCombo_1HS(NA_NORMAL4, NA_DODGE_BACK);
	DefCombo_1HS(NA_NORMAL4, NA_DODGE_LEFT);
	DefCombo_1HS(NA_NORMAL4, NA_DODGE_RIGHT);
	DefCombo_1HS(NA_NORMAL4, NA_USE_TALENT__CLIENT_ONLY);
	DefCombo_1HS(NA_NORMAL4, NA_GUARD__CLIENT_ONLY);

	DefCombo_1HS(NA_NORMAL5, NA_SUPER);
	DefCombo_1HS(NA_NORMAL5, NA_UPPER);
	DefCombo_1HS(NA_NORMAL5, NA_DODGE_FRONT);
	DefCombo_1HS(NA_NORMAL5, NA_DODGE_BACK);
	DefCombo_1HS(NA_NORMAL5, NA_DODGE_LEFT);
	DefCombo_1HS(NA_NORMAL5, NA_DODGE_RIGHT);
	DefCombo_1HS(NA_NORMAL5, NA_USE_TALENT__CLIENT_ONLY);
	DefCombo_1HS(NA_NORMAL5, NA_GUARD__CLIENT_ONLY);

	DefCombo_1HS(NA_SUPER, NA_ADVANCE);
	
	DefCombo_1HS(NA_ADVANCE, NA_NORMAL2);
	DefCombo_1HS(NA_ADVANCE, NA_DODGE_FRONT);
	DefCombo_1HS(NA_ADVANCE, NA_DODGE_BACK);
	DefCombo_1HS(NA_ADVANCE, NA_DODGE_LEFT);
	DefCombo_1HS(NA_ADVANCE, NA_DODGE_RIGHT);


	DefCombo_1HS(NA_SWORD_DRAWING, NA_NORMAL2);
	DefCombo_1HS(NA_SWORD_DRAWING, NA_UPPER);
	DefCombo_1HS(NA_SWORD_DRAWING, NA_DODGE_BACK);
	DefCombo_1HS(NA_SWORD_DRAWING, NA_DODGE_LEFT);
	DefCombo_1HS(NA_SWORD_DRAWING, NA_DODGE_RIGHT);


	DefCombo_1HS(NA_DODGE_FRONT, NA_NORMAL1);
	DefCombo_1HS(NA_DODGE_FRONT, NA_SUPER);
	DefCombo_1HS(NA_DODGE_FRONT, NA_ADVANCE);
	DefCombo_1HS(NA_DODGE_BACK, NA_NORMAL1);
	DefCombo_1HS(NA_DODGE_LEFT, NA_NORMAL1);
	DefCombo_1HS(NA_DODGE_RIGHT, NA_NORMAL1);

	DefCombo_1HS(NA_GUARD__CLIENT_ONLY, NA_USE_TALENT__CLIENT_ONLY);

	// 1hb -----------------------------------------------------
	DefCombo_1HB(NA_NORMAL1, NA_NORMAL2);
	DefCombo_1HB(NA_NORMAL1, NA_SUPER);
	DefCombo_1HB(NA_NORMAL1, NA_ADVANCE);
	DefCombo_1HB(NA_NORMAL1, NA_UPPER);
	DefCombo_1HB(NA_NORMAL1, NA_DODGE_FRONT);
	DefCombo_1HB(NA_NORMAL1, NA_DODGE_BACK);
	DefCombo_1HB(NA_NORMAL1, NA_DODGE_LEFT);
	DefCombo_1HB(NA_NORMAL1, NA_DODGE_RIGHT);
	DefCombo_1HB(NA_NORMAL1, NA_USE_TALENT__CLIENT_ONLY);
	DefCombo_1HB(NA_NORMAL1, NA_GUARD__CLIENT_ONLY);

	DefCombo_1HB(NA_NORMAL2, NA_NORMAL3);
	DefCombo_1HB(NA_NORMAL2, NA_UPPER);
	DefCombo_1HB(NA_NORMAL2, NA_DODGE_FRONT);
	DefCombo_1HB(NA_NORMAL2, NA_DODGE_BACK);
	DefCombo_1HB(NA_NORMAL2, NA_DODGE_LEFT);
	DefCombo_1HB(NA_NORMAL2, NA_DODGE_RIGHT);
	DefCombo_1HB(NA_NORMAL2, NA_USE_TALENT__CLIENT_ONLY);
	DefCombo_1HB(NA_NORMAL2, NA_GUARD__CLIENT_ONLY);

	DefCombo_1HB(NA_NORMAL3, NA_NORMAL4);
	DefCombo_1HB(NA_NORMAL3, NA_SUPER);
	DefCombo_1HB(NA_NORMAL3, NA_ADVANCE);
	DefCombo_1HB(NA_NORMAL3, NA_UPPER);
	DefCombo_1HB(NA_NORMAL3, NA_DODGE_FRONT);
	DefCombo_1HB(NA_NORMAL3, NA_DODGE_BACK);
	DefCombo_1HB(NA_NORMAL3, NA_DODGE_LEFT);
	DefCombo_1HB(NA_NORMAL3, NA_DODGE_RIGHT);
	DefCombo_1HB(NA_NORMAL3, NA_USE_TALENT__CLIENT_ONLY);
	DefCombo_1HB(NA_NORMAL3, NA_GUARD__CLIENT_ONLY);

	DefCombo_1HB(NA_NORMAL4, NA_NORMAL5);
	DefCombo_1HB(NA_NORMAL4, NA_UPPER);
	DefCombo_1HB(NA_NORMAL4, NA_DODGE_FRONT);
	DefCombo_1HB(NA_NORMAL4, NA_DODGE_BACK);
	DefCombo_1HB(NA_NORMAL4, NA_DODGE_LEFT);
	DefCombo_1HB(NA_NORMAL4, NA_DODGE_RIGHT);
	DefCombo_1HB(NA_NORMAL4, NA_USE_TALENT__CLIENT_ONLY);
	DefCombo_1HB(NA_NORMAL4, NA_GUARD__CLIENT_ONLY);

	DefCombo_1HB(NA_NORMAL5, NA_SUPER);
	DefCombo_1HB(NA_NORMAL5, NA_UPPER);
	DefCombo_1HB(NA_NORMAL5, NA_DODGE_FRONT);
	DefCombo_1HB(NA_NORMAL5, NA_DODGE_BACK);
	DefCombo_1HB(NA_NORMAL5, NA_DODGE_LEFT);
	DefCombo_1HB(NA_NORMAL5, NA_DODGE_RIGHT);
	DefCombo_1HB(NA_NORMAL5, NA_USE_TALENT__CLIENT_ONLY);
	DefCombo_1HB(NA_NORMAL5, NA_GUARD__CLIENT_ONLY);

	DefCombo_1HB(NA_SUPER, NA_ADVANCE);

	DefCombo_1HB(NA_ADVANCE, NA_NORMAL2);
	DefCombo_1HB(NA_ADVANCE, NA_DODGE_FRONT);
	DefCombo_1HB(NA_ADVANCE, NA_DODGE_BACK);
	DefCombo_1HB(NA_ADVANCE, NA_DODGE_LEFT);
	DefCombo_1HB(NA_ADVANCE, NA_DODGE_RIGHT);

	DefCombo_1HB(NA_SWORD_DRAWING, NA_NORMAL2);
	DefCombo_1HB(NA_SWORD_DRAWING, NA_UPPER);
	DefCombo_1HB(NA_SWORD_DRAWING, NA_DODGE_BACK);
	DefCombo_1HB(NA_SWORD_DRAWING, NA_DODGE_LEFT);
	DefCombo_1HB(NA_SWORD_DRAWING, NA_DODGE_RIGHT);


	DefCombo_1HB(NA_DODGE_FRONT, NA_NORMAL1);
	DefCombo_1HB(NA_DODGE_FRONT, NA_SUPER);
	DefCombo_1HB(NA_DODGE_FRONT, NA_ADVANCE);
	DefCombo_1HB(NA_DODGE_BACK, NA_NORMAL1);
	DefCombo_1HB(NA_DODGE_LEFT, NA_NORMAL1);
	DefCombo_1HB(NA_DODGE_RIGHT, NA_NORMAL1);

	DefCombo_1HB(NA_GUARD__CLIENT_ONLY, NA_USE_TALENT__CLIENT_ONLY);

	// 1hp -----------------------------------------------------
	DefCombo_1HP(NA_NORMAL1, NA_NORMAL2);
	DefCombo_1HP(NA_NORMAL1, NA_UPPER);
	DefCombo_1HP(NA_NORMAL1, NA_DODGE_FRONT);
	DefCombo_1HP(NA_NORMAL1, NA_DODGE_BACK);
	DefCombo_1HP(NA_NORMAL1, NA_DODGE_LEFT);
	DefCombo_1HP(NA_NORMAL1, NA_DODGE_RIGHT);
	DefCombo_1HP(NA_NORMAL1, NA_USE_TALENT__CLIENT_ONLY);


	DefCombo_1HP(NA_NORMAL2, NA_NORMAL3);
	DefCombo_1HP(NA_NORMAL2, NA_UPPER);
	DefCombo_1HP(NA_NORMAL2, NA_DODGE_FRONT);
	DefCombo_1HP(NA_NORMAL2, NA_DODGE_BACK);
	DefCombo_1HP(NA_NORMAL2, NA_DODGE_LEFT);
	DefCombo_1HP(NA_NORMAL2, NA_DODGE_RIGHT);
	DefCombo_1HP(NA_NORMAL2, NA_USE_TALENT__CLIENT_ONLY);

//	DefCombo_1HP(NA_NORMAL3, NA_NORMAL4);
	DefCombo_1HP(NA_NORMAL3, NA_ADVANCE);
	DefCombo_1HP(NA_NORMAL3, NA_UPPER);
	DefCombo_1HP(NA_NORMAL3, NA_DODGE_FRONT);
	DefCombo_1HP(NA_NORMAL3, NA_DODGE_BACK);
	DefCombo_1HP(NA_NORMAL3, NA_DODGE_LEFT);
	DefCombo_1HP(NA_NORMAL3, NA_DODGE_RIGHT);
	DefCombo_1HP(NA_NORMAL3, NA_USE_TALENT__CLIENT_ONLY);

	//DefCombo_1HP(NA_NORMAL4, NA_UPPER);
	//DefCombo_1HP(NA_NORMAL4, NA_USE_TALENT__CLIENT_ONLY);

	DefCombo_1HP(NA_ADVANCE, NA_NORMAL2);

	DefCombo_1HP(NA_UPPER, NA_UPPER);
	DefCombo_1HP(NA_UPPER, NA_DODGE_BACK);
	DefCombo_1HP(NA_UPPER, NA_DODGE_LEFT);
	DefCombo_1HP(NA_UPPER, NA_DODGE_RIGHT);

	DefCombo_1HP(NA_SWORD_DRAWING, NA_NORMAL2);
	DefCombo_1HP(NA_SWORD_DRAWING, NA_UPPER);

	// 2hd -----------------------------------------------------
	DefCombo_2HD(NA_NORMAL1, NA_NORMAL2);
	DefCombo_2HD(NA_NORMAL1, NA_SUPER);
	DefCombo_2HD(NA_NORMAL1, NA_UPPER);
	DefCombo_2HD(NA_NORMAL1, NA_DODGE_FRONT);
	DefCombo_2HD(NA_NORMAL1, NA_DODGE_BACK);
	DefCombo_2HD(NA_NORMAL1, NA_DODGE_LEFT);
	DefCombo_2HD(NA_NORMAL1, NA_DODGE_RIGHT);
	DefCombo_2HD(NA_NORMAL1, NA_USE_TALENT__CLIENT_ONLY);
	DefCombo_2HD(NA_NORMAL1, NA_GUARD__CLIENT_ONLY);

	DefCombo_2HD(NA_NORMAL2, NA_NORMAL3);
	DefCombo_2HD(NA_NORMAL2, NA_SUPER);
	DefCombo_2HD(NA_NORMAL2, NA_UPPER);
	DefCombo_2HD(NA_NORMAL2, NA_DODGE_FRONT);
	DefCombo_2HD(NA_NORMAL2, NA_DODGE_BACK);
	DefCombo_2HD(NA_NORMAL2, NA_DODGE_LEFT);
	DefCombo_2HD(NA_NORMAL2, NA_DODGE_RIGHT);
	DefCombo_2HD(NA_NORMAL2, NA_USE_TALENT__CLIENT_ONLY);
	DefCombo_2HD(NA_NORMAL2, NA_GUARD__CLIENT_ONLY);

	DefCombo_2HD(NA_NORMAL3, NA_UPPER);
	DefCombo_2HD(NA_NORMAL3, NA_DODGE_FRONT);
	DefCombo_2HD(NA_NORMAL3, NA_DODGE_BACK);
	DefCombo_2HD(NA_NORMAL3, NA_DODGE_LEFT);
	DefCombo_2HD(NA_NORMAL3, NA_DODGE_RIGHT);
	DefCombo_2HD(NA_NORMAL3, NA_USE_TALENT__CLIENT_ONLY);
	DefCombo_2HD(NA_NORMAL3, NA_GUARD__CLIENT_ONLY);

	DefCombo_2HD(NA_ADVANCE, NA_NORMAL2);
	DefCombo_2HD(NA_ADVANCE, NA_DODGE_FRONT);
	DefCombo_2HD(NA_ADVANCE, NA_DODGE_BACK);
	DefCombo_2HD(NA_ADVANCE, NA_DODGE_LEFT);
	DefCombo_2HD(NA_ADVANCE, NA_DODGE_RIGHT);

	DefCombo_2HD(NA_SWORD_DRAWING, NA_NORMAL2);
	DefCombo_2HD(NA_SWORD_DRAWING, NA_UPPER);
	DefCombo_2HD(NA_SWORD_DRAWING, NA_DODGE_BACK);
	DefCombo_2HD(NA_SWORD_DRAWING, NA_DODGE_LEFT);
	DefCombo_2HD(NA_SWORD_DRAWING, NA_DODGE_RIGHT);


//	DefCombo_2HD(NA_DODGE_BACK, NA_DODGE_BACK);

	DefCombo_2HD(NA_ADVANCE, NA_UPPER);

	// 2hb -----------------------------------------------------
	DefCombo_2HB(NA_NORMAL1, NA_NORMAL2);
	DefCombo_2HB(NA_NORMAL1, NA_SUPER);
	DefCombo_2HB(NA_NORMAL1, NA_UPPER);
	DefCombo_2HB(NA_NORMAL1, NA_DODGE_FRONT);
	DefCombo_2HB(NA_NORMAL1, NA_DODGE_BACK);
	DefCombo_2HB(NA_NORMAL1, NA_DODGE_LEFT);
	DefCombo_2HB(NA_NORMAL1, NA_DODGE_RIGHT);
	DefCombo_2HB(NA_NORMAL1, NA_USE_TALENT__CLIENT_ONLY);
	DefCombo_2HB(NA_NORMAL1, NA_GUARD__CLIENT_ONLY);

	DefCombo_2HB(NA_NORMAL2, NA_NORMAL3);
	DefCombo_2HB(NA_NORMAL2, NA_SUPER);
	DefCombo_2HB(NA_NORMAL2, NA_UPPER);
	DefCombo_2HB(NA_NORMAL2, NA_DODGE_FRONT);
	DefCombo_2HB(NA_NORMAL2, NA_DODGE_BACK);
	DefCombo_2HB(NA_NORMAL2, NA_DODGE_LEFT);
	DefCombo_2HB(NA_NORMAL2, NA_DODGE_RIGHT);
	DefCombo_2HB(NA_NORMAL2, NA_USE_TALENT__CLIENT_ONLY);
	DefCombo_2HB(NA_NORMAL2, NA_GUARD__CLIENT_ONLY);

	DefCombo_2HB(NA_NORMAL3, NA_UPPER);
	DefCombo_2HB(NA_NORMAL3, NA_DODGE_FRONT);
	DefCombo_2HB(NA_NORMAL3, NA_DODGE_BACK);
	DefCombo_2HB(NA_NORMAL3, NA_DODGE_LEFT);
	DefCombo_2HB(NA_NORMAL3, NA_DODGE_RIGHT);
	DefCombo_2HB(NA_NORMAL3, NA_USE_TALENT__CLIENT_ONLY);
	DefCombo_2HB(NA_NORMAL3, NA_GUARD__CLIENT_ONLY);

	DefCombo_2HB(NA_ADVANCE, NA_NORMAL2);
	DefCombo_2HB(NA_ADVANCE, NA_DODGE_FRONT);
	DefCombo_2HB(NA_ADVANCE, NA_DODGE_BACK);
	DefCombo_2HB(NA_ADVANCE, NA_DODGE_LEFT);
	DefCombo_2HB(NA_ADVANCE, NA_DODGE_RIGHT);

	DefCombo_2HB(NA_SWORD_DRAWING, NA_NORMAL2);
	DefCombo_2HB(NA_SWORD_DRAWING, NA_UPPER);
	DefCombo_2HB(NA_SWORD_DRAWING, NA_DODGE_BACK);
	DefCombo_2HB(NA_SWORD_DRAWING, NA_DODGE_LEFT);
	DefCombo_2HB(NA_SWORD_DRAWING, NA_DODGE_RIGHT);

	DefCombo_2HB(NA_ADVANCE, NA_UPPER);

	// staff -----------------------------------------------------
	DefCombo_STAFF(NA_NORMAL1, NA_NORMAL2);
	DefCombo_STAFF(NA_NORMAL1, NA_SUPER);
	DefCombo_STAFF(NA_NORMAL1, NA_UPPER);
	DefCombo_STAFF(NA_NORMAL1, NA_DODGE_FRONT);
	DefCombo_STAFF(NA_NORMAL1, NA_DODGE_BACK);
	DefCombo_STAFF(NA_NORMAL1, NA_DODGE_LEFT);
	DefCombo_STAFF(NA_NORMAL1, NA_DODGE_RIGHT);
	DefCombo_STAFF(NA_NORMAL1, NA_USE_TALENT__CLIENT_ONLY);

	DefCombo_STAFF(NA_NORMAL2, NA_NORMAL3);
	DefCombo_STAFF(NA_NORMAL2, NA_SUPER);
	DefCombo_STAFF(NA_NORMAL2, NA_UPPER);
	DefCombo_STAFF(NA_NORMAL2, NA_DODGE_FRONT);
	DefCombo_STAFF(NA_NORMAL2, NA_DODGE_BACK);
	DefCombo_STAFF(NA_NORMAL2, NA_DODGE_LEFT);
	DefCombo_STAFF(NA_NORMAL2, NA_DODGE_RIGHT);
	DefCombo_STAFF(NA_NORMAL2, NA_USE_TALENT__CLIENT_ONLY);

	DefCombo_STAFF(NA_NORMAL3, NA_NORMAL4);
	DefCombo_STAFF(NA_NORMAL3, NA_UPPER);
	DefCombo_STAFF(NA_NORMAL3, NA_SUPER);
	DefCombo_STAFF(NA_NORMAL3, NA_UPPER);
	DefCombo_STAFF(NA_NORMAL3, NA_DODGE_FRONT);
	DefCombo_STAFF(NA_NORMAL3, NA_DODGE_BACK);
	DefCombo_STAFF(NA_NORMAL3, NA_DODGE_LEFT);
	DefCombo_STAFF(NA_NORMAL3, NA_DODGE_RIGHT);
	DefCombo_STAFF(NA_NORMAL3, NA_USE_TALENT__CLIENT_ONLY);

	DefCombo_STAFF(NA_NORMAL4, NA_UPPER);
	DefCombo_STAFF(NA_NORMAL4, NA_DODGE_FRONT);
	DefCombo_STAFF(NA_NORMAL4, NA_DODGE_BACK);
	DefCombo_STAFF(NA_NORMAL4, NA_DODGE_LEFT);
	DefCombo_STAFF(NA_NORMAL4, NA_DODGE_RIGHT);
	DefCombo_STAFF(NA_NORMAL4, NA_USE_TALENT__CLIENT_ONLY);
	DefCombo_STAFF(NA_NORMAL4, NA_GUARD__CLIENT_ONLY);

	DefCombo_STAFF(NA_ADVANCE, NA_NORMAL2);
	DefCombo_STAFF(NA_ADVANCE, NA_DODGE_FRONT);
	DefCombo_STAFF(NA_ADVANCE, NA_DODGE_BACK);
	DefCombo_STAFF(NA_ADVANCE, NA_DODGE_LEFT);
	DefCombo_STAFF(NA_ADVANCE, NA_DODGE_RIGHT);

	DefCombo_STAFF(NA_SWORD_DRAWING, NA_NORMAL2);
	DefCombo_STAFF(NA_SWORD_DRAWING, NA_DODGE_BACK);
	DefCombo_STAFF(NA_SWORD_DRAWING, NA_DODGE_LEFT);
	DefCombo_STAFF(NA_SWORD_DRAWING, NA_DODGE_RIGHT);

	// dwp -----------------------------------------------------
	DefCombo_DWP(NA_NORMAL1, NA_NORMAL2);
	DefCombo_DWP(NA_NORMAL1, NA_SUPER);
	DefCombo_DWP(NA_NORMAL1, NA_UPPER);
	DefCombo_DWP(NA_NORMAL1, NA_DODGE_FRONT);
	DefCombo_DWP(NA_NORMAL1, NA_DODGE_BACK);
	DefCombo_DWP(NA_NORMAL1, NA_DODGE_LEFT);
	DefCombo_DWP(NA_NORMAL1, NA_DODGE_RIGHT);
	DefCombo_DWP(NA_NORMAL1, NA_USE_TALENT__CLIENT_ONLY);

	DefCombo_DWP(NA_NORMAL2, NA_NORMAL3);
	DefCombo_DWP(NA_NORMAL2, NA_SUPER);
	DefCombo_DWP(NA_NORMAL2, NA_UPPER);
	DefCombo_DWP(NA_NORMAL2, NA_DODGE_FRONT);
	DefCombo_DWP(NA_NORMAL2, NA_DODGE_BACK);
	DefCombo_DWP(NA_NORMAL2, NA_DODGE_LEFT);
	DefCombo_DWP(NA_NORMAL2, NA_DODGE_RIGHT);
	DefCombo_DWP(NA_NORMAL2, NA_USE_TALENT__CLIENT_ONLY);

	DefCombo_DWP(NA_NORMAL3, NA_NORMAL4);
	DefCombo_DWP(NA_NORMAL3, NA_SUPER);
	DefCombo_DWP(NA_NORMAL3, NA_ADVANCE);
	DefCombo_DWP(NA_NORMAL3, NA_UPPER);
	DefCombo_DWP(NA_NORMAL3, NA_DODGE_FRONT);
	DefCombo_DWP(NA_NORMAL3, NA_DODGE_BACK);
	DefCombo_DWP(NA_NORMAL3, NA_DODGE_LEFT);
	DefCombo_DWP(NA_NORMAL3, NA_DODGE_RIGHT);
	DefCombo_DWP(NA_NORMAL3, NA_USE_TALENT__CLIENT_ONLY);

	DefCombo_DWP(NA_NORMAL4, NA_NORMAL5);
	DefCombo_DWP(NA_NORMAL4, NA_SUPER);
	DefCombo_DWP(NA_NORMAL4, NA_UPPER);
	DefCombo_DWP(NA_NORMAL4, NA_USE_TALENT__CLIENT_ONLY);

	DefCombo_DWP(NA_NORMAL5, NA_NORMAL6);
	DefCombo_DWP(NA_NORMAL5, NA_SUPER);
	DefCombo_DWP(NA_NORMAL5, NA_UPPER);
	DefCombo_DWP(NA_NORMAL5, NA_USE_TALENT__CLIENT_ONLY);

	DefCombo_DWP(NA_NORMAL6, NA_SUPER);
	DefCombo_DWP(NA_NORMAL6, NA_UPPER);
	DefCombo_DWP(NA_NORMAL6, NA_USE_TALENT__CLIENT_ONLY);

	DefCombo_DWP(NA_ADVANCE, NA_NORMAL1);

	DefCombo_DWP(NA_UPPER, NA_UPPER);
	DefCombo_DWP(NA_UPPER, NA_DODGE_BACK);
	DefCombo_DWP(NA_UPPER, NA_DODGE_LEFT);
	DefCombo_DWP(NA_UPPER, NA_DODGE_RIGHT);

	DefCombo_DWP(NA_SWORD_DRAWING, NA_UPPER);

	DefCombo_DWP(NA_GUARD__CLIENT_ONLY, NA_USE_TALENT__CLIENT_ONLY);
}

//////////////////////////////////////

XSpecialActionTransChecker::XSpecialActionTransChecker( XMyPlayer* pMyPlayer, XMyTalent* pMyTalent ) : m_pPlayer(pMyPlayer), m_pMyTalent(pMyTalent)
{
	
}

void XSpecialActionTransChecker::DefTrans( WEAPON_TYPE nWeaponType, SPECIAL_ACTION_COMMAND nSpecialAction, TALENT_NORMAL_ATTACK_TYPE normalAttack )
{
	m_TransTable.m_Table[nWeaponType][nSpecialAction].nAttackType = normalAttack;
}

void XSpecialActionTransChecker::DefTrans_AllWeapons( SPECIAL_ACTION_COMMAND nSpecialAction, TALENT_NORMAL_ATTACK_TYPE attackType )
{
	for (int i = 0; i < WEAPON_MAX; i++)
	{
		DefTrans(WEAPON_TYPE(i), nSpecialAction, attackType);
	}
}

void XSpecialActionTransChecker::DefConst( WEAPON_TYPE nWeaponType, TALENT_NORMAL_ATTACK_TYPE attackType, XNormalAttackTypeConstraint& constraint )
{
	m_ConstraintTable.m_Table[nWeaponType][attackType] = constraint;
}

void XSpecialActionTransChecker::DefConst_AllWeapons( TALENT_NORMAL_ATTACK_TYPE attackType, XNormalAttackTypeConstraint& constraint )
{
	for (int i = 0; i < WEAPON_MAX; i++)
	{
		DefConst(WEAPON_TYPE(i), attackType, constraint);
	}
}

TALENT_NORMAL_ATTACK_TYPE XSpecialActionTransChecker::Trans( SPECIAL_ACTION_COMMAND nSpecialActionCommand )
{
	const WEAPON_TYPE nWeaponType = m_pPlayer->GetCurrWeaponType();
	const TALENT_NORMAL_ATTACK_TYPE nNextNormalAttackType = m_TransTable.m_Table[nWeaponType][nSpecialActionCommand].nAttackType;

	return nNextNormalAttackType;
}

bool XSpecialActionTransChecker::CheckConst( TALENT_NORMAL_ATTACK_TYPE nPrevNormalAttackType, TALENT_NORMAL_ATTACK_TYPE nNextNormalAttackType )
{
	const WEAPON_TYPE nWeaponType = m_pPlayer->GetCurrWeaponType();
	XNormalAttackTypeConstraint& constraint = m_ConstraintTable.m_Table[nWeaponType][nNextNormalAttackType];

	// 패시브 탤런트 체크
	if (constraint.nCheckPassiveType != TEPT_NONE)
	{
		if (m_pMyTalent->HasExtraPassiveTalent(constraint.nCheckPassiveType) == false) return false;
	}

	// 스탠스 체크
	CHAR_STANCE nStance = m_pPlayer->GetStance();
	if ( !((nStance == CS_NORMAL) && (constraint.nCheckStances & _STANCE_NORMAL)) &&
		!((nStance == CS_BATTLE) && (constraint.nCheckStances & _STANCE_BATTLE)) )
	{
		return false;
	}

	// 콤보 체크
	if (nPrevNormalAttackType != NA_NA)
	{
		XNormalAttackTypeConstraintTable::COMBO_ENABLED_ATTACK_SET& comboEnabledAttackTypeSet = m_ConstraintTable.m_ComboEnabledAttackType[nWeaponType][nPrevNormalAttackType];
		if (comboEnabledAttackTypeSet.find(nNextNormalAttackType) == comboEnabledAttackTypeSet.end())
		{
			return false;
		}
	}

	return true;
}

void XSpecialActionTransChecker::DefCombo( WEAPON_TYPE nWeaponType, TALENT_NORMAL_ATTACK_TYPE attackType, TALENT_NORMAL_ATTACK_TYPE enabledNextAttack )
{
	m_ConstraintTable.m_ComboEnabledAttackType[nWeaponType][attackType].insert(enabledNextAttack);
}

void XSpecialActionTransChecker::DefCombo_AllWeapons( TALENT_NORMAL_ATTACK_TYPE attackType, TALENT_NORMAL_ATTACK_TYPE enabledNextAttack )
{
	for (int i = 0; i < WEAPON_MAX; i++)
	{
		DefCombo(WEAPON_TYPE(i), attackType, enabledNextAttack);
	}
}

void XSpecialActionTransChecker::DefCombo_1HS( TALENT_NORMAL_ATTACK_TYPE attackType, TALENT_NORMAL_ATTACK_TYPE enabledNextAttack )
{
	DefCombo(WEAPON_1H_SLASH, attackType, enabledNextAttack);
}

void XSpecialActionTransChecker::DefCombo_2HD( TALENT_NORMAL_ATTACK_TYPE attackType, TALENT_NORMAL_ATTACK_TYPE enabledNextAttack )
{
	DefCombo(WEAPON_TWO_HANDED, attackType, enabledNextAttack);
}

void XSpecialActionTransChecker::DefCombo_1HB( TALENT_NORMAL_ATTACK_TYPE attackType, TALENT_NORMAL_ATTACK_TYPE enabledNextAttack )
{
	DefCombo(WEAPON_1H_BLUNT, attackType, enabledNextAttack);
}

void XSpecialActionTransChecker::DefCombo_STAFF( TALENT_NORMAL_ATTACK_TYPE attackType, TALENT_NORMAL_ATTACK_TYPE enabledNextAttack )
{
	DefCombo(WEAPON_STAFF, attackType, enabledNextAttack);
}

void XSpecialActionTransChecker::DefCombo_1HP( TALENT_NORMAL_ATTACK_TYPE attackType, TALENT_NORMAL_ATTACK_TYPE enabledNextAttack )
{
	DefCombo(WEAPON_1H_PIERCE, attackType, enabledNextAttack);
}

void XSpecialActionTransChecker::DefCombo_DWP( TALENT_NORMAL_ATTACK_TYPE attackType, TALENT_NORMAL_ATTACK_TYPE enabledNextAttack )
{
	DefCombo(WEAPON_DUAL_PIERCE, attackType, enabledNextAttack);
}

void XSpecialActionTransChecker::DefCombo_2HB( TALENT_NORMAL_ATTACK_TYPE attackType, TALENT_NORMAL_ATTACK_TYPE enabledNextAttack )
{
	DefCombo(WEAPON_2H_BLUNT, attackType, enabledNextAttack);
}