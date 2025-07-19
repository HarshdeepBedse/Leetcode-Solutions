# Write your MySQL query statement below
select firstname,lastname,city,state 
From person
left join address
ON person.personID=Address.personId;