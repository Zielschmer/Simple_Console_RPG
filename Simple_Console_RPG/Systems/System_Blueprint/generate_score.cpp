#include "generate_components.h"

int pickScore(std::vector<int>& scoreOrder) {
	int score = rand() % 6;
	for (int k = 0; k < scoreOrder.size(); k++) {
		if (score == scoreOrder[k]) {
			score = pickScore(scoreOrder);
		}
	}
	return score;
}

int calculateExtra(int& extraPoints) {
	int currentExtra = rand() % 9;
	if (extraPoints < currentExtra) {
		currentExtra = calculateExtra(extraPoints);
	}
	return currentExtra;
}

Score_ptr generateScore(ID& entityID) {
	Score_ptr newScore(new CompScore(entityID));

	srand(time(NULL) + entityID);

	std::vector<int> scoreOrder;
	scoreOrder.push_back(rand() % 6);
	for (int j = 0; j < 5; j++) {
		scoreOrder.push_back(pickScore(scoreOrder));
	}
	int scoreValues[6];
	int extraPoints = 27u;
	for (int j = 0; j < 6; j++) {
		if (extraPoints > 0u) {
			int addExtra = calculateExtra(extraPoints);
			scoreValues[scoreOrder[j]] = 8u + addExtra;
			extraPoints -= addExtra;
		}
		else {
			scoreValues[scoreOrder[j]] = 8u;
		}
	}
	int l = 0;
	while (extraPoints > 0) {
		if (scoreValues[scoreOrder[l]] < 18u) {
			scoreValues[scoreOrder[l]]++;
			extraPoints--;
		}
		l++;
		if (l == 6) {
			l = 0;
		}
	}

	newScore->m_str = scoreValues[0];
	newScore->m_dex = scoreValues[1];
	newScore->m_con = scoreValues[2];
	newScore->m_int = scoreValues[3];
	newScore->m_fth = scoreValues[4];
	newScore->m_lck = scoreValues[5];

	return std::move(newScore);
}