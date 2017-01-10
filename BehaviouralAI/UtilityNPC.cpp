#include "UtilityNPC.h"

void UtilitySystem::UtilityNPC::selectAction(float a_fdeltaTime)
{
	m_waterValue.setValue(getWaterValue());

	float fBestScore = 0.0f;
	std::string strBestAction;

	for (auto score : m_pUtilityScoreMap)
	{
		float fThisScore = score.second->getUtilityScore();
		if (fThisScore > fBestScore)
		{
			fBestScore = fThisScore;
			strBestAction = score.first;
		}
	}

	if (strBestAction == "collectWater")
	{
		collectWater(a_fdeltaTime);
	}

	if (strBestAction == "collectFood")
	{
		collectFood(a_fdeltaTime);
	}

	if (strBestAction == "collectRest")
	{
		rest(a_fdeltaTime);
	}
}