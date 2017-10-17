/*
Rest In Peace ApocalypseCheats
*/

#pragma once

#include "Hacks.h"

Vector GetAutostrafeView();

class CMiscHacks : public CHack
{
public:
	void Init();
	void Draw();
	void Move(CUserCmd *pCmd, bool &bSendPacket);
	void CustomName();
private:
	void HAutoJump(CUserCmd *pCmd);
	void AutoJump(CUserCmd *pCmd);
	void LBYINDICATOR();
	void AutoJumpSMAC(CUserCmd *pCmd);
	void EdgeJump(CUserCmd *pCmd);
	void Walkbot(CUserCmd *pCmd);
	void PerfectStrafe(CUserCmd *pCmd);
	void LegitStrafe(CUserCmd *pCmd);
	void RageStrafe(CUserCmd *pCmd);

	//void ChatSpamAchievement();
	//void NameDispersion();
	//void ChatSpamAchievement();

	//std::string GetNameChange();

	/*void ChatSpam();
	void Namechanger();

	std::string GetRegularSpam();
	std::string GetCustomSpam();
	std::string GetPlayerSpam();
	std::string GetSinglePlayerSpam();

	std::string GetNameChange();
	std::string GetNameCalloutChange();*/
};



