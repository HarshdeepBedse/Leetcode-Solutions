# Write your MySQL query statement below
SELECT 
    CASE 
                  
        WHEN COUNT(*) = 1 THEN NULL     -- Only one salary
        ELSE MIN(salary)                        -- Second highest
    END AS SecondHighestSalary
FROM (
    SELECT DISTINCT salary
    FROM Employee 
    ORDER BY salary DESC
    LIMIT 2
) AS top_two;

