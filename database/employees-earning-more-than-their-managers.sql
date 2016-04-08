Select e1.Name
From Employee as e1
Inner join Employee as e2 on e1.ManagerId = e2.Id and e1.Salary >= e2.Salary;
