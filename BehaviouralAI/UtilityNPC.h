#ifndef UTILITYNPC_
#define UTILITYNPC_
#include "src/World.h"
#include "src/BaseNPC.h"
#include "src/UtilityValue.h"
#include "src/UtilityScore.h"
#include <map>

namespace UtilitySystem
{
	enum class Resource { Water, Food, Rest, Logs, BuildHouse };

	class UtilityNPC : public BaseNPC
	{
	public:
		UtilityNPC(World* pWorld) : BaseNPC(m_pWorld)
		{
			m_waterValue.setNormalizationType(UtilityValue::INVERSE_LINEAR);
			m_waterValue.setMinMaxValues(0, 20);
			m_waterValue.setValue(getWaterValue());

			m_foodValue.setNormalizationType(UtilityValue::INVERSE_LINEAR);
			m_foodValue.setMinMaxValues(5, 25);
			m_foodValue.setValue(getFoodValue());

			m_restValue.setNormalizationType(UtilityValue::INVERSE_LINEAR);
			m_restValue.setMinMaxValues(1, 20);
			m_restValue.setValue(getRestValue());

			m_logValue.setNormalizationType(UtilityValue::INVERSE_LINEAR);
			m_logValue.setMinMaxValues(0, 1);
			m_logValue.setValue(getNumberOfLogs());

			UtilityScore* pWaterScore = new UtilityScore();
			pWaterScore->addUtilityValue(&m_waterValue, 1.0f);
			m_pUtilityScoreMap[Resource::Water] = pWaterScore;

			UtilityScore* pFoodScore = new UtilityScore();
			pFoodScore->addUtilityValue(&m_foodValue, 1.0f);
			m_pUtilityScoreMap[Resource::Food] = pFoodScore;

			UtilityScore* pRestScore = new UtilityScore();
			pRestScore->addUtilityValue(&m_restValue, 1.0f);
			m_pUtilityScoreMap[Resource::Rest] = pRestScore;

			UtilityScore* pLogScore = new UtilityScore();
			pLogScore->addUtilityValue(&m_restValue, 1.0f);
			m_pUtilityScoreMap[Resource::Logs] = pLogScore;
		}
		~UtilityNPC();

	private:
		UtilityValue m_waterValue;
		UtilityValue m_foodValue;
		UtilityValue m_restValue;
		UtilityValue m_logValue;
		UtilityValue m_buildValue;
		std::map<Resource, UtilityScore*> m_pUtilityScoreMap;
		//std::map<std::string, UtilityScore*> m_pUtilityScoreMap;
		
	protected:
		void selectAction(float a_fdeltaTime) override;
		/*UtilityScore* pWaterScore = new UtilityScore();
		UtilityScore* pFoodScore = new UtilityScore();
		UtilityScore* pRestScore = new UtilityScore();
		UtilityScore* pLogScore = new UtilityScore();*/
	};
}

#endif