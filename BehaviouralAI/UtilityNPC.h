#ifndef UTILITYNPC_
#define UTILITYNPC_
#include "src/World.h"
#include "src/BaseNPC.h"
#include "src/UtilityValue.h"
#include "src/UtilityScore.h"
#include <map>
using namespace UtilitySystem;

//namespace UtilitySystem
//{
	//enum class Resource { Water, Food, Rest, Logs, BuildHouse };

	class UtilityNPC : public BaseNPC
	{
	public:
		UtilityNPC(World* pWorld); /* : BaseNPC(m_pWorld)*/
		~UtilityNPC();

	private:
		UtilityValue m_waterValue;
		UtilityValue m_foodValue;
		UtilityValue m_restValue;
		UtilityValue m_logValue;
		UtilityValue m_buildValue;
		std::map<std::string, UtilityScore*> m_pUtilityScoreMap;
		//std::map<std::string, UtilityScore*> m_pUtilityScoreMap;
		
	protected:
		void selectAction(float a_fdeltaTime) override;
		/*UtilityScore* pWaterScore = new UtilityScore();
		UtilityScore* pFoodScore = new UtilityScore();
		UtilityScore* pRestScore = new UtilityScore();
		UtilityScore* pLogScore = new UtilityScore();*/
	};
//}

#endif