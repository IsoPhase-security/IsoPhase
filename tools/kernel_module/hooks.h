#pragma once

#include <linux/syscalls.h>
#include "types.h"

typedef asmlinkage int (*sys_mkdir_t)(const char *, int);
asmlinkage int mkdir_hook(const char *, int);

// typedef asmlinkage int (*sys_open_t)(const char *pathname, int flags);
// asmlinkage int open_hook(const char *pathname, int flags);

typedef asmlinkage int (*sys_open2_t)(const char *, int, mode_t);
asmlinkage int open_hook(const char *, int, mode_t);

typedef asmlinkage long (*sys_execve_t)(const char __user * filename, const char __user * const __user * argv, const char __user * const __user * envp);
asmlinkage long execve_hook(const char __user * filename, const char __user * const __user * argv, const char __user * const __user * envp);

typedef asmlinkage int (*sys_unlink_t)(const char *pathname);
asmlinkage int unlink_hook(const char *pathname);

typedef asmlinkage int (*sys_unlinkat_t)(int dirfd, const char *pathname, int flags);
asmlinkage int unlinkat_hook(int dirfd, const char *pathname, int flags);

typedef asmlinkage int (*sys_chmod_t)(const char *pathname, mode_t mode);
asmlinkage int chmod_hook(const char *pathname, mode_t mode);

typedef asmlinkage int (*sys_fchmod_t)(int fd, mode_t mode);
asmlinkage int fchmod_hook(int fd, mode_t mode);

typedef asmlinkage int (*sys_fchmodat_t)(int dirfd, const char *pathname, mode_t mode, int flags);
asmlinkage int fchmodat_hook(int dirfd, const char *pathname, mode_t mode, int flags);

// typedef asmlinkage pid_t (*sys_fork_t)(void);
// asmlinkage pid_t fork_hook(void);

typedef asmlinkage long (*sys_read_t)(unsigned int fd, char __user *buf, size_t count);
asmlinkage long read_hook(unsigned int fd, char __user *buf, size_t count);

typedef asmlinkage long (*sys_write_t)(unsigned int fd, const char __user *buf, size_t count);
asmlinkage long write_hook(unsigned int fd, const char __user *buf, size_t count);

typedef asmlinkage int (*sys_chown_t)(const char *pathname, uid_t owner, gid_t group);
asmlinkage int chown_hook(const char *pathname, uid_t owner, gid_t group);

typedef asmlinkage int (*sys_fchown_t)(int fd, uid_t owner, gid_t group);
asmlinkage int fchown_hook(int fd, uid_t owner, gid_t group);

typedef asmlinkage int (*sys_lchown_t)(const char *pathname, uid_t owner, gid_t group);
asmlinkage int lchown_hook(const char *pathname, uid_t owner, gid_t group);

typedef asmlinkage int (*sys_fchownat_t)(int dirfd, const char *pathname, uid_t owner, gid_t group, int flags);
asmlinkage int fchownat_hook(int dirfd, const char *pathname, uid_t owner, gid_t group, int flags);



