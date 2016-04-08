select DISTINCT Email from Person group by Email having count(Email) > 1;
