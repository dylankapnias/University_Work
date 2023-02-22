USE u18108467_upbank;

#6.2
SELECT c.companyCode FROM
CONTRACTS as c JOIN (SELECT ATM.companyCode FROM
					ATM JOIN 	(SELECT BRANCH.id FROM
								BRANCH JOIN ADDRESS ON BRANCH.id = ADDRESS.Oid WHERE
                                ADDRESS.suburb = 'Groenkloof') as b ON ATM.responsibleBranch = b.id) as a ON c.companyCode = a.companyCode;
                                
#6.3
with cte as (SELECT a.accountNumber, COUNT(*) as amountOfTransactions FROM
			ACCOUNT as a JOIN TRANSACTION as t ON
			(a.accountNumber = t.fromAccount) OR (a.accountNumber = t.toAccount) GROUP BY
			a.accountNumber)
SELECT * FROM
cte WHERE
amountOfTransactions > 24;