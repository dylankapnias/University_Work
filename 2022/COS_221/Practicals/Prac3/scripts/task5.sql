USE u18108467_upbank;

# 5.1
SELECT c.prefix, c.first, c.middle, c.last, a.streetNumber, a.street FROM
CLIENTS AS c JOIN ADDRESS as a ON c.id = a.Oid;

# 5.2
SET SQL_SAFE_UPDATES = 0;
UPDATE ACCOUNT SET
ownerBranch = 'B0000003' WHERE
ownerBranch = 	(SELECT b.id FROM
				BRANCH as b JOIN ADDRESS as a ON b.id = a.Oid WHERE
				a.suburb = "Randburg");
SET SQL_SAFE_UPDATES = 1;

#5.3
SELECT c.id, c.prefix, c.first, c.middle, c.last FROM
CLIENTS as c LEFT JOIN VALIDATION as v ON
c.id = v.clientId WHERE
v.clientId IS NULL;

#5.4
SET SQL_SAFE_UPDATES = 0;
UPDATE ATM SET
responsibleBranch = 'B0000002' WHERE
responsibleBranch = (SELECT DISTINCT ATM.responsibleBranch FROM
					ATM JOIN BRANCH as b ON
					ATM.responsibleBranch = b.id WHERE
					ATM.responsibleBranch = (SELECT b.id FROM
											BRANCH as b JOIN ADDRESS as a ON b.id = a.Oid WHERE
											a.suburb = "Randburg"));
SET SQL_SAFE_UPDATES = 1;

#5.5
SELECT a.accountNumber, COUNT(*) as amountOfTransactions FROM
ACCOUNT as a JOIN TRANSACTION as t ON
(a.accountNumber = t.fromAccount) OR (a.accountNumber = t.toAccount) GROUP BY
a.accountNumber;