/* This file was generated by ODB, object-relational mapping (ORM)
 * compiler for C++.
 */

DROP TABLE IF EXISTS "CharacterLink" CASCADE;

CREATE TABLE "CharacterLink" (
  "id" BIGSERIAL NOT NULL PRIMARY KEY,
  "serverId" INTEGER NOT NULL,
  "char_name" TEXT NOT NULL,
  "acc_name" TEXT NOT NULL);

