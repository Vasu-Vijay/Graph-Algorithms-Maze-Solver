class MedianFinder {
  private:
    vector<int> minHeap, maxHeap;
    int s1 = 0, s2 = 0;

    void print(vector<int> &v) {
        for (int i = 0; i < v.size(); i++) {
            //cout << v[i] << ", ";
        }
        //cout << endl;
    }

    void swap(vector<int> &v, int i, int j) {
        int tmp = v[i];
        v[i] = v[j];
        v[j] = tmp;
    }

    void addToMin(int val) {
        //cout << "called addtomin" << val << "\n";
        minHeap.push_back(val);
        s1++;
        int i = s1 - 1;
        while ((i - 1) / 2 >= 0 && minHeap[(i - 1) / 2] > minHeap[i]) {
            swap(minHeap, (i - 1) / 2, i);
            i = (i - 1) / 2;
        }
    }

    void addToMax(int val) {
        //cout << "called addtomax, " << val << "\n";
        maxHeap.push_back(val);
        s2++;
        int i = s2 - 1;
        while ((i - 1) / 2 >= 0 && maxHeap[(i - 1) / 2] < maxHeap[i]) {
            swap(maxHeap, (i - 1) / 2, i);
            i = (i - 1) / 2;
        }
    }

    int removeFromMin() {
        //cout << "called remfrommin\n";
        int last = minHeap.back();
        int first = minHeap[0];
        minHeap.pop_back();
        s1--;
        minHeap[0] = last;
        int i = 0;
        while (2 * i + 2 < s1) {
            int swap_child =
                minHeap[2 * i + 1] < minHeap[2 * i + 2] ? 2 * i + 1 : 2 * i + 2;
            if (minHeap[swap_child] < minHeap[i]) {
                swap(minHeap, i, swap_child);
                i = swap_child;
            } else {
                break;
            }
        }
        if (2 * i + 1 < s1 && minHeap[2 * i + 1] < minHeap[i]) {
            swap(minHeap, i, 2 * i + 1);
        }
        return first;
    }

    int removeFromMax() {
        //cout << "called remfrommax\n";
        int last = maxHeap.back();
        int first = maxHeap[0];
        maxHeap.pop_back();
        s2--;
        maxHeap[0] = last;
        int i = 0;
        while (2 * i + 2 < s2) {
            int swap_child =
                maxHeap[2 * i + 1] > maxHeap[2 * i + 2] ? 2 * i + 1 : 2 * i + 2;
            if (maxHeap[swap_child] > maxHeap[i]) {
                swap(maxHeap, i, swap_child);
                i = swap_child;
            } else {
                break;
            }
        }
        if (2 * i + 1 < s2 && maxHeap[2 * i + 1] > maxHeap[i]) {
            swap(maxHeap, i, 2 * i + 1);
        }
        return first;
    }

  public:
    MedianFinder() {
        // add inits
    }

    void addNum(int num) {
        //cout << "adding " << num << endl;
        if (minHeap.empty() || num > minHeap[0]) {
            addToMin(num);
        } else if (maxHeap.empty() || num < maxHeap[0]) {
            addToMax(num);
        } else {
            if (s1 == s2) {
                addToMin(num);
            } else {
                addToMax(num);
            }
        }
        print(minHeap);
        print(maxHeap);
        if (s1 - s2 == 2) {
            int val = removeFromMin();
            addToMax(val);
        } else if (s1 - s2 == -1) {
            int val = removeFromMax();
            addToMin(val);
        }
        print(minHeap);
        print(maxHeap);
    }

    double findMedian() {
        if (s1 == s2) {
            return static_cast<double>(minHeap[0] + maxHeap[0]) / 2;
        } else {
            return minHeap[0];
        }
    }
};