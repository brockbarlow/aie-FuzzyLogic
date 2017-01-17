#include "UtilityNPC.h"

UtilityNPC::UtilityNPC(World* pWorld) : BaseNPC(pWorld)
{
	m_waterValue.setNormalizationType(UtilityValue::INVERSE_LINEAR);
	m_waterValue.setMinMaxValues(0, 30);
	m_waterValue.setValue(getWaterValue());
	UtilityScore* pWaterScore = new UtilityScore();
	pWaterScore->addUtilityValue(&m_waterValue, 1.0f);
	m_pUtilityScoreMap["GET WATER"] = pWaterScore;

	m_foodValue.setNormalizationType(UtilityValue::INVERSE_LINEAR);
	m_foodValue.setMinMaxValues(1, 40);
	m_foodValue.setValue(getFoodValue());
	UtilityScore* pFoodScore = new UtilityScore();
	pFoodScore->addUtilityValue(&m_foodValue, 1.0f);
	m_pUtilityScoreMap["GET FOOD"] = pFoodScore;

	m_restValue.setNormalizationType(UtilityValue::INVERSE_LINEAR);
	m_restValue.setMinMaxValues(3, 27);
	m_restValue.setValue(getRestValue());
	UtilityScore* pRestScore = new UtilityScore();
	pRestScore->addUtilityValue(&m_restValue, 1.0f);
	m_pUtilityScoreMap["GO SLEEP"] = pRestScore;

	m_logValue.setNormalizationType(UtilityValue::INVERSE_LINEAR);
	m_logValue.setMinMaxValues(0, 1);
	m_logValue.setValue(getNumberOfLogs());
	UtilityScore* pLogScore = new UtilityScore();
	pLogScore->addUtilityValue(&m_restValue, 1.0f);
	m_pUtilityScoreMap["GET WOOD"] = pLogScore;

	m_buildValue.setNormalizationType(UtilityValue::LINEAR);
	m_buildValue.setMinMaxValues(0, 50);
	m_buildValue.setValue(getNumberOfLogs());
	UtilityScore* pBuildScore = new UtilityScore();
	pBuildScore->addUtilityValue(&m_buildValue, 1.0f);
	m_pUtilityScoreMap["BUILD HOUSE"] = pBuildScore;
}

UtilityNPC::~UtilityNPC()
{

}

void UtilityNPC::selectAction(float a_fdeltaTime)
{
	m_waterValue.setValue(getWaterValue());
	m_foodValue.setValue(getFoodValue());
	m_restValue.setValue(getRestValue());
	m_logValue.setValue(getNumberOfLogs());
	m_buildValue.setValue(getNumberOfLogs());

	float fBestScore = 0.0f;
	//Resource strBestAction = Resource::BuildHouse;
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

	if (strBestAction == "GET WATER") //Resource::Water
	{
		collectWater(a_fdeltaTime);
	}
	else if (strBestAction == "GET FOOD") //Resource::Food
	{
		collectFood(a_fdeltaTime);
	}
	else if (strBestAction == "GO SLEEP") //Resource::Rest
	{
		rest(a_fdeltaTime);
	}
	else if (strBestAction == "GET WOOD") //Resource::Logs
	{
		chopTree(a_fdeltaTime);
	}
	else if (getNumberOfLogs() > 0 && strBestAction == "BUILD HOUSE") //Resource::BuildHouse
	{
		buildHouse(a_fdeltaTime);
	}
}