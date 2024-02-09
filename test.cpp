
    // Execute the statement and fetch rows
    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        // Loop through each column in the current row
        for (int i = 0; i < sqlite3_column_count(stmt); i++) {
            // Print the column name
            std::cout << sqlite3_column_name(stmt, i) << ": ";

            // Print the value based on the column type
            switch (sqlite3_column_type(stmt, i)) {
                case SQLITE_INTEGER:
                    std::cout << sqlite3_column_int(stmt, i);
                    break;
                case SQLITE_FLOAT:
                    std::cout << sqlite3_column_double(stmt, i);
                    break;
                case SQLITE_TEXT:
                    std::cout << sqlite3_column_text(stmt, i);
                    break;
                case SQLITE_NULL:
                    std::cout << "NULL";
                    break;
                default:
                    std::cout << "Unknown data type";
                    break;
            }
            std::cout << "\t";
        }
        std::cout << std::endl;
    }

    // Check if the loop exited due to an error
    if (rc != SQLITE_DONE) {
        std::cerr << "Error reading data: " << sqlite3_errmsg(db) << std::endl;
    }

    // Finalize the statement and close the database
    sqlite3_finalize(stmt);
    sqlite3_close(db);

    return 0;
}


