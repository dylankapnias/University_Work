USE u18108467_upbank;

DROP TABLE IF EXISTS OWNED;
DROP TABLE IF EXISTS VALIDATION;
DROP TABLE IF EXISTS CONTRACTS;
DROP TABLE IF EXISTS ATM;
DROP TABLE IF EXISTS TRANSACTION;
DROP TABLE IF EXISTS ACCOUNT;
DROP TABLE IF EXISTS CONTACTDETAILS;
DROP TABLE IF EXISTS ADDRESS;
DROP TABLE IF EXISTS BRANCH;
DROP TABLE IF EXISTS CLIENTS;
DROP TABLE IF EXISTS OWNERS;

CREATE TABLE OWNERS (
	id					VARCHAR(8)	NOT NULL	,
    PRIMARY KEY (id)
);

CREATE TABLE CLIENTS (
	id					VARCHAR(8)	NOT NULL	,
    prefix				VARCHAR(4)  NOT NULL	,
    first				VARCHAR(20) NOT NULL	,
    middle				VARCHAR(20) 			,
    last				VARCHAR(20) NOT NULL	,
    PRIMARY KEY (id)
);

CREATE TABLE BRANCH (
	id					VARCHAR(8)	NOT NULL	,
    open				VARCHAR(5)  NOT NULL	,
    close				VARCHAR(5)  NOT NULL	,
    day					VARCHAR(9)  NOT NULL	,
    PRIMARY KEY (id)							,
    CONSTRAINT CHK_O_Time CHECK (open regexp '^[0-1]{1}[0-9]{1}:[0-5]{1}[0-9]{1}$'),
    CONSTRAINT CHK_C_Time CHECK (close regexp '^[0-1]{1}[0-9]{1}:[0-5]{1}[0-9]{1}$')
);

CREATE TABLE ADDRESS (
	Oid					VARCHAR(8)	NOT NULL	,
    a_type				VARCHAR(20) NOT NULL	,
    streetNumber		VARCHAR(4) 	NOT NULL	,
    street				VARCHAR(20) NOT NULL	,
    suburb				VARCHAR(20) NOT NULL	,
    city				VARCHAR(20) NOT NULL	,
    postalCode			VARCHAR(5) 	NOT NULL	,
    PRIMARY KEY (Oid, postalCode)				,
    FOREIGN KEY (Oid) REFERENCES OWNERS(id)
);

CREATE TABLE CONTACTDETAILS (
	Oid					VARCHAR(8)	NOT NULL	,
    c_type				VARCHAR(20) NOT NULL	,
    identifier			VARCHAR(30) NOT NULL	,
    PRIMARY KEY (Oid, identifier)				,
    FOREIGN KEY (Oid) REFERENCES OWNERS(id)
);

CREATE TABLE ACCOUNT (
	accountNumber		VARCHAR(8)	NOT NULL	,
    amount				FLOAT		NOT NULL	,
    currency			VARCHAR(3)  NOT NULL	,
    isSavings			BOOLEAN 	NOT NULL	,
    interest_rate		FLOAT 		NOT NULL	,
    noticePeriod		INT 		NOT NULL	,
    isSharia			BOOLEAN		NOT NULL	,
    clientId			VARCHAR(8)	NOT NULL	,
    ownerBranch			VARCHAR(8)  NOT NULL	,
    ownedId				VARCHAR(8) NOT NULL	 	,
    PRIMARY KEY (accountNumber)
);

CREATE TABLE TRANSACTION (
	transactionCode 	VARCHAR(10)	NOT NULL	,
    transactionDate 	VARCHAR(10) NOT NULL	,
    amount				FLOAT       NOT NULL	,
    currency			VARCHAR(10) NOT NULL	,
    toAccount			VARCHAR(8)  NOT NULL	,
    fromAccount			VARCHAR(8)  NOT NULL	,
    PRIMARY KEY (transactionCode)				,
    FOREIGN KEY (fromAccount) REFERENCES ACCOUNT(accountNumber),
    CONSTRAINT CHK_Date CHECK (transactionDate regexp '^[0-9]{4}-[0-9]{2}-[0-9]{2}$')
);

CREATE TABLE ATM (
	serialNumber		VARCHAR(8)	NOT NULL	,
    f_date				VARCHAR(10) NOT NULL	,
    companyCode			VARCHAR(8)  NOT NULL	,
    cashOnHand			FLOAT       NOT NULL	,
    responsibleBranch	VARCHAR(8)  NOT NULL	,
    ownedId				VARCHAR(8)  NOT NULL	,
    PRIMARY KEY (serialNumber)					,
    CONSTRAINT CHK_Date CHECK (f_date regexp '^[0-9]{4}-[0-9]{2}-[0-9]{2}$')
);

CREATE TABLE CONTRACTS (
	companyCode			VARCHAR(8)	NOT NULL	,
    start				VARCHAR(10) NOT NULL	,
    end					VARCHAR(10) NOT NULL	,
    atmSerialNumber		VARCHAR(10) NOT NULL	,
    PRIMARY KEY (companyCode)					,
    FOREIGN KEY (atmSerialNumber) REFERENCES ATM(serialNumber),
    CONSTRAINT CHK_S_Date CHECK (start regexp '^[0-9]{4}-[0-9]{2}-[0-9]{2}$'),
    CONSTRAINT CHK_E_Date CHECK (end regexp '^[0-9]{4}-[0-9]{2}-[0-9]{2}$')
);

CREATE TABLE VALIDATION (
	clientId			VARCHAR(8)	NOT NULL	,
    v_type				VARCHAR(20) NOT NULL	,
    identifier			VARCHAR(20) NOT NULL	,
    document			VARCHAR(20) NOT NULL	,
    PRIMARY KEY (clientId, v_type)				,
    FOREIGN KEY (clientId) REFERENCES CLIENTS(id)
);

CREATE TABLE OWNED (
	owendId				VARCHAR(8)	NOT NULL	,
    PRIMARY KEY (owendId)
);