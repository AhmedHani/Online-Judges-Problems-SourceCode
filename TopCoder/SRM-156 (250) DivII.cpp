class DiskSpace {
public:
  int minDrives(vector <int> used, vector <int> total) {
            int AllData = 0;
            for(int i = 0; i < used.size(); i++) {
                AllData += used[i];
            }
            sort(total.begin(), total.end());
            int Counter = 0;
            for(int i = total.size() - 1; AllData > 0; i--) {
                AllData -= total[i];
                Counter++;
            }
	}
};
