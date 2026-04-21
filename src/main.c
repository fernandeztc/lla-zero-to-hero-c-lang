#include <assert.h>
#include <stdio.h>
#include <kv.h>

int main() {
  // kv_t *table = kv_init(1024);
  // printf("%p\n", table);
  // printf("%ld\n", table->capacity);

  // kv_put(table, "hehe", "haha");
  // kv_put(table, "hehe", "hoho");
  // kv_put(table, "lala", "baba");

  // for (int i = 0; i < table->capacity; i++) {
  //   if(table->entries[i].key) {
  //     printf("[%d] %s: %s\n", 
  //             i,
  //             table->entries[i].key, 
  //             table->entries[i].value);
  //   }
  // }

  // char *val = kv_get(table, "hehe");
  // char *val2 = kv_get(table, "lala");
  // char *val3 = kv_get(table, "this_doesnt_exist");

  // printf("%s %s %s\n", val, val2, val3);

  // kv_delete(table, "hehe");
  // val = NULL;
  // val = kv_get(table, "hehe");

  // printf("%s %s %s\n", val, val2, val3);

  // kv_free(table);
  kv_t *db = kv_init(16);

  kv_put(db, "name", "alice");
  kv_put(db, "city", "berlin");

  assert(kv_delete(db, "name") == 0);
  assert(kv_get(db, "name") == NULL);
  assert(db->count == 1);

  assert(kv_delete(db, "missing") == -1);

  kv_free(db);
}
