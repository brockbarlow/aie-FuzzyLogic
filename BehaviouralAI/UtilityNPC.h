#ifndef UTILITYNPC_
#define UTILITYNPC_
#include "src/BaseNPC.h"
#include "src/UtilityValue.h"
#include "src/UtilityScore.h"
#include <map>

namespace UtilitySystem
{
	class UtilityNPC : public BaseNPC
	{
	public:
		UtilityNPC(World* pWorld) : BaseNPC(m_pWorld)
		{
			m_waterValue.setNormalizationType(UtilityValue::INVERSE_LINEAR);
			m_waterValue.setMinMaxValues(0, 20);
			m_waterValue.setValue(getWaterValue());

			m_foodValue.setNormalizationType(UtilityValue::INVERSE_LINEAR);
			m_foodValue.setMinMaxValues(0, 15);
			m_foodValue.setValue(getFoodValue());

			m_restValue.setNormalizationType(UtilityValue::INVERSE_LINEAR);
			m_restValue.setMinMaxValues(0, 17);
			m_restValue.setValue(getRestValue());

			UtilityScore* pWaterScore = new UtilityScore();
			pWaterScore->addUtilityValue(&m_waterValue, 1.0f);
			m_pUtilityScoreMap["collectWater"] = pWaterScore;

			UtilityScore* pFoodScore = new UtilityScore();
			pFoodScore->addUtilityValue(&m_foodValue, 1.0f);
			m_pUtilityScoreMap["collectFood"] = pFoodScore;

			UtilityScore* pRestScore = new UtilityScore();
			pRestScore->addUtilityValue(&m_restValue, 1.0f);
			m_pUtilityScoreMap["collectRest"] = pRestScore;
		}
		~UtilityNPC();

	private:
		UtilityValue m_waterValue;
		UtilityValue m_foodValue;
		UtilityValue m_restValue;

		std::map<std::string, UtilityScore*> m_pUtilityScoreMap;
		
	protected:
		void selectAction(float a_fdeltaTime) override;
		UtilityScore* pWaterScore = new UtilityScore();
		UtilityScore* pFoodScore = new UtilityScore();
		UtilityScore* pRestScore = new UtilityScore();
	};
}

#endif