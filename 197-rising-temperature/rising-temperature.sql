# Write your MySQL query statement below
#self join
SELECT a.id
FROM Weather a JOIN Weather b
WHERE DATEDIFF(a.recordDate, b.recordDate) = 1 AND a.temperature > b.temperature;