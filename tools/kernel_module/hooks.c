#include <linux/module.h>
#include "hooks.h"
#include "sys_hook.h"
#include <linux/sched.h>

#define DEBUG 1
extern struct sys_hook *lkh_sys_hook;

asmlinkage int mkdir_hook(const char *path, int mode)
{
    sys_mkdir_t sys_mkdir;
    
    sys_mkdir = (sys_mkdir_t)sys_hook_get_orig64(lkh_sys_hook, __NR_mkdir);
if(DEBUG)
{
    printk("mkdir is hooked\n");
    printk("The process id is %d\n", (int) task_pid_nr(current));
    printk("The process vid is %d\n", (int) task_pid_vnr(current));
    printk("The process name is %s\n", current->comm);
    printk("\n\n");
}
    return sys_mkdir(path, mode);
}

// asmlinkage int open_hook(const char *pathname, int flags)
// {
//     sys_open_t sys_open;
//     sys_open = (sys_open_t)sys_hook_get_orig64(lkh_sys_hook,__NR_open);
//     printk("open is hooked\n");
//     printk("The process id is %d\n", (int) task_pid_nr(current));
//     printk("The process vid is %d\n", (int) task_pid_vnr(current));
//     printk("The process name is %s\n", current->comm);
//     printk("\n\n");

//     return sys_open(pathname,flags);
// } 
asmlinkage int open_hook(const char *pathname, int flags, mode_t mode)
{
    sys_open2_t sys_open;
    sys_open = (sys_open2_t)sys_hook_get_orig64(lkh_sys_hook,__NR_open);
if(DEBUG)
{
    printk("open is hooked\n");
    printk("The process id is %d\n", (int) task_pid_nr(current));
    printk("The process vid is %d\n", (int) task_pid_vnr(current));
    printk("The process name is %s\n", current->comm);
    printk("\n\n");
}
    return sys_open(pathname,flags,mode);

}

asmlinkage long execve_hook(const char __user * filename,
				const char __user * const __user * argv,
				const char __user * const __user * envp)
{
    sys_execve_t sys_execve;
    sys_execve = (sys_execve_t)sys_hook_get_orig64(lkh_sys_hook,__NR_execve);
if(DEBUG)
{
    printk("execve is hooked\n");
    printk("The process id is %d\n", (int) task_pid_nr(current));
    printk("The process vid is %d\n", (int) task_pid_vnr(current));
    printk("The process name is %s\n", current->comm);
    printk("\n\n");
}
    return sys_execve(filename,argv,envp);
}

asmlinkage int unlink_hook(const char *pathname)
{
    sys_unlink_t sys_unlink;
    sys_unlink = (sys_unlink_t)sys_hook_get_orig64(lkh_sys_hook,__NR_unlink);
if(DEBUG)
{
    printk("unlink is hooked\n");
    printk("The process id is %d\n", (int) task_pid_nr(current));
    printk("The process vid is %d\n", (int) task_pid_vnr(current));
    printk("The process name is %s\n", current->comm);
    printk("\n\n");
}
    return sys_unlink(pathname);
}

asmlinkage int unlinkat_hook(int dirfd, const char *pathname, int flags)
{
    sys_unlinkat_t sys_unlinkat;
    sys_unlinkat = (sys_unlinkat_t)sys_hook_get_orig64(lkh_sys_hook,__NR_unlinkat);
if(DEBUG)
{
    printk("unlinkat is hooked\n");
    printk("The process id is %d\n", (int) task_pid_nr(current));
    printk("The process vid is %d\n", (int) task_pid_vnr(current));
    printk("The process name is %s\n", current->comm);
    printk("\n\n");
}
    return sys_unlinkat(dirfd,pathname,flags);
}

asmlinkage int chmod_hook(const char *pathname, mode_t mode)
{
    sys_chmod_t sys_chmod;
    sys_chmod = (sys_chmod_t)sys_hook_get_orig64(lkh_sys_hook,__NR_chmod);
if(DEBUG)
{
    printk("chmod is hooked\n");
    printk("The process id is %d\n", (int) task_pid_nr(current));
    printk("The process vid is %d\n", (int) task_pid_vnr(current));
    printk("The process name is %s\n", current->comm);
}
    return sys_chmod(pathname,mode);
}

asmlinkage int fchmod_hook(int fd, mode_t mode)
{
    sys_fchmod_t sys_fchmod;
    sys_fchmod = (sys_fchmod_t)sys_hook_get_orig64(lkh_sys_hook,__NR_fchmod);
if(DEBUG)
{
    printk("fchmod is hooked\n");
    printk("The process id is %d\n", (int) task_pid_nr(current));
    printk("The process vid is %d\n", (int) task_pid_vnr(current));
    printk("The process name is %s\n", current->comm);
}
    return sys_fchmod(fd,mode);
}

asmlinkage int fchmodat_hook(int dirfd, const char *pathname, mode_t mode, int flags)
{
    sys_fchmodat_t sys_fchmodat;
    sys_fchmodat = (sys_fchmodat_t)sys_hook_get_orig64(lkh_sys_hook,__NR_fchmodat);
if(DEBUG)
{
    printk("fchmodat is hooked\n");
    printk("The process id is %d\n", (int) task_pid_nr(current));
    printk("The process vid is %d\n", (int) task_pid_vnr(current));
    printk("The process name is %s\n", current->comm);
}
    return sys_fchmodat(dirfd,pathname,mode,flags);
}

// asmlinkage pid_t fork_hook()
// {
//     sys_fork_t sys_fork;
//     sys_fork = (sys_fork_t)sys_hook_get_orig64(lkh_sys_hook,__NR_fork);
// if(DEBUG)
// {
//     printk("fork is hooked\n");
//     printk("The process id is %d\n", (int) task_pid_nr(current));
//     printk("The process vid is %d\n", (int) task_pid_vnr(current));
//     printk("The process name is %s\n", current->comm);
// }
//     return sys_fork();
// }

asmlinkage int chown_hook(const char *pathname, uid_t owner, gid_t group)
{
    sys_chown_t sys_chown;
    sys_chown = (sys_chown_t)sys_hook_get_orig64(lkh_sys_hook,__NR_chown);
if(DEBUG)
{
    printk("chown is hooked\n");
    printk("The process id is %d\n", (int) task_pid_nr(current));
    printk("The process vid is %d\n", (int) task_pid_vnr(current));
    printk("The process name is %s\n", current->comm);
}
    return sys_chown(pathname,owner,group);
}

asmlinkage int fchown_hook(int fd, uid_t owner, gid_t group)
{
    sys_fchown_t sys_fchown;
    sys_fchown = (sys_fchown_t)sys_hook_get_orig64(lkh_sys_hook,__NR_fchown);
if(DEBUG)
{
    printk("fchown is hooked\n");
    printk("The process id is %d\n", (int) task_pid_nr(current));
    printk("The process vid is %d\n", (int) task_pid_vnr(current));
    printk("The process name is %s\n", current->comm);
}
    return sys_fchown(fd,owner,group);
}

asmlinkage int lchown_hook(const char *pathname, uid_t owner, gid_t group)
{
    sys_lchown_t sys_lchown;
    sys_lchown = (sys_lchown_t)sys_hook_get_orig64(lkh_sys_hook,__NR_lchown);
if(DEBUG)
{
    printk("lchown is hooked\n");
    printk("The process id is %d\n", (int) task_pid_nr(current));
    printk("The process vid is %d\n", (int) task_pid_vnr(current));
    printk("The process name is %s\n", current->comm);
}
    return sys_lchown(pathname,owner,group);
}
asmlinkage int fchownat_hook(int dirfd, const char *pathname, uid_t owner, gid_t group, int flags)
{
    sys_fchownat_t sys_fchownat;
    sys_fchownat = (sys_fchownat_t)sys_hook_get_orig64(lkh_sys_hook,__NR_fchownat);
if(DEBUG)
{
    printk("fchownat is hooked\n");
    printk("The process id is %d\n", (int) task_pid_nr(current));
    printk("The process vid is %d\n", (int) task_pid_vnr(current));
    printk("The process name is %s\n", current->comm);
}
    return sys_fchownat(dirfd,pathname,owner,group,flags);
}

asmlinkage long read_hook(unsigned int fd, char __user *buf, size_t count)
{
    sys_read_t sys_read;
    sys_read = (sys_read_t)sys_hook_get_orig64(lkh_sys_hook,__NR_read);
if(DEBUG)
{
    printk("read is hooked\n");
    printk("The process id is %d\n", (int) task_pid_nr(current));
    printk("The process vid is %d\n", (int) task_pid_vnr(current));
    printk("The process name is %s\n", current->comm);
}
    return sys_read(fd,buf,count);    
}

asmlinkage long write_hook(unsigned int fd, const char __user *buf, size_t count)
{
    sys_write_t sys_write;
    sys_write = (sys_write_t)sys_hook_get_orig64(lkh_sys_hook,__NR_write);
if(DEBUG)
{
    printk("write is hooked\n");
    printk("The process id is %d\n", (int) task_pid_nr(current));
    printk("The process vid is %d\n", (int) task_pid_vnr(current));
    printk("The process name is %s\n", current->comm);
}
    return sys_write(fd,buf,count);    
}