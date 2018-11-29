/* sepolicy.h - Header for magiskpolicy non-public APIs
 */

#ifndef _SEPOLICY_H
#define _SEPOLICY_H

#include <sepol/policydb/policydb.h>

#ifdef __cplusplus
extern "C" {
#endif

// Global policydb
extern policydb_t *policydb;

// hashtab traversal macro
#define hashtab_for_each(table, ptr) \
	for (int _i = 0; _i < table->size; ++_i) \
		for (*ptr = table->htable[_i]; *ptr != NULL; *ptr = (*ptr)->next)

// sepolicy manipulation functions
void for_each_avtab_node(void (*callback)(avtab_ptr_t));
int create_domain(const char *d);
int set_domain_state(const char *s, int state);
int add_typeattribute(const char *domainS, const char *attr);
int add_rule(const char *s, const char *t, const char *c, const char *p, int effect, int n);
int add_xperm_rule(const char *s, const char *t, const char *c, const char *range, int effect, int n);
int add_type_rule(const char *s, const char *t, const char *c, const char *d, int effect);

#ifdef __cplusplus
};
#endif

#endif
