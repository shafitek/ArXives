// https://leetcode.com/problems/employee-importance/

/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int sum_so_far = 0;
        for (int i = 0; i < employees.size(); i++) {
            if (employees[i]->id == id) {
                sum_so_far = employees[i]->importance;
                for(int j = 0; j < employees[i]->subordinates.size(); j++) {
                    sum_so_far += getImportance(employees, employees[i]->subordinates[j]);     
                }
                break;
            }
        }
        return sum_so_far;
    }
};