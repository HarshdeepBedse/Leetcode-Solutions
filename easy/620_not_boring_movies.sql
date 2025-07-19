# Write your MySQL query statement below
SELECT * FROM Cinema
WHERE cinema.id%2=1 AND cinema.description!="boring"
ORDER BY cinema.rating DESC;