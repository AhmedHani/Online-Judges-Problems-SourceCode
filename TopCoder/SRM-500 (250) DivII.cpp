class SRMCards {
public:
  int maxTurns(vector <int> cards) {
            int Counter = 0;
            sort(cards.begin(), cards.end());
            for(int i = 0; i < cards.size(); i++) {
                if(i < cards.size() - 1 && cards[i] == cards[i + 1] - 1) {
                        Counter++, i++;
                } else {
                    Counter++;
                }
            }
            return Counter;
	}
};
