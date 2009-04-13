#ifndef IMAGE_SEARCH_POSTGRESQL_H
#define IMAGE_SEARCH_POSTGRESQL_H

#include "Database.h"

#include <pqxx/connection>

#include <string>
#include <memory>

namespace ImageSearch
{

  class PostgresQl : public Database {
  public:
    PostgresQl (const std::string &hostAddr,
		const std::string &dbName,
		const std::string &userName,
		const std::string &password,
		int dbImageRows, int dbImageCols, int nKeptCoeffs);
    virtual ~PostgresQl (void);
    virtual void save (const DBImage &image);
    virtual int getLastId (void);
    virtual DbImageList findAll (void);
    virtual std::auto_ptr<DBImage> getById (int id);
  private:
    std::string getTableName (void);
    std::auto_ptr<pqxx::connection> createConnection (void);
    std::string m_hostAddr;
    std::string m_dbName;
    std::string m_userName;
    std::string m_password;
    int m_dbImgRows;
    int m_dbImgCols;
    int m_nKeptCoeffs;
  };

};

#endif // IMAGE_SEARCH_POSTGRESQL_H
