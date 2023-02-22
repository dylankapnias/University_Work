Recreating The Database:

1. If you wish to create a new database for the use of restoring from the dump, first run the following command [without the apostrophe's (')]:
'mysqladmin -u your_username -p create name_of_new_database'. [i.e. mysqladmin -u admin -p create db_from_dump]

2. Run the following command to restore the database from the dump [without the apostrophe's (')]:
'mysql -u your_username -p name_of_database_to_restore_into < path_to_the_dump'. [i.e. mysql -u admin -p db_from_dump < prac2_dump.sql]