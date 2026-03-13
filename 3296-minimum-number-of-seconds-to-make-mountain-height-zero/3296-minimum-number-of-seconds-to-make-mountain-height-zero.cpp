class Solution {
public:
    pair<double, double> quadSolver(double a, double b, double c) {
        double D = b * b - 4 * a * c;

        double root1 = (-b + sqrt(D)) / (2 * a);
        double root2 = (-b - sqrt(D)) / (2 * a);

        return {root1, root2};
    }

    bool isPossible(long long mid, int mountainHeight,
                    vector<int>& workerTimes) {
        long long sum = 0;
        int n = workerTimes.size();

        for (int t : workerTimes) {
            auto roots = quadSolver(t, t, -2 * mid);
            double r = max(roots.first, roots.second);

            long long k = (long long)floor(r);

            sum += k;
            if (sum >= mountainHeight)
                return true;
        }
        return false;
    }
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        sort(workerTimes.begin(), workerTimes.end());
        int n = workerTimes.size();

        long long minTime = 0;
        long long maxTime = (long long)workerTimes[0] * mountainHeight *
                            (mountainHeight + 1) / 2;

        long long l = minTime, h = maxTime;
        long long ans = h;

        while (l <= h) {
            long long mid = l + (h - l) / 2;
            if (isPossible(mid, mountainHeight, workerTimes)) {
                ans = mid;
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};