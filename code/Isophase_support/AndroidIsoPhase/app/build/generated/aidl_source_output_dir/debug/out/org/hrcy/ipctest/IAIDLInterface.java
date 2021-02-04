/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package org.hrcy.ipctest;
public interface IAIDLInterface extends android.os.IInterface
{
  /** Default implementation for IAIDLInterface. */
  public static class Default implements org.hrcy.ipctest.IAIDLInterface
  {
    @Override public java.util.List<org.hrcy.ipctest.Student> getStudent() throws android.os.RemoteException
    {
      return null;
    }
    @Override public void setStudent(org.hrcy.ipctest.Student student) throws android.os.RemoteException
    {
    }
    @Override public void sendRequest(java.lang.String APIName) throws android.os.RemoteException
    {
    }
    @Override public void sendShm(android.os.SharedMemory shm_object) throws android.os.RemoteException
    {
    }
    @Override
    public android.os.IBinder asBinder() {
      return null;
    }
  }
  /** Local-side IPC implementation stub class. */
  public static abstract class Stub extends android.os.Binder implements org.hrcy.ipctest.IAIDLInterface
  {
    private static final java.lang.String DESCRIPTOR = "org.hrcy.ipctest.IAIDLInterface";
    /** Construct the stub at attach it to the interface. */
    public Stub()
    {
      this.attachInterface(this, DESCRIPTOR);
    }
    /**
     * Cast an IBinder object into an org.hrcy.ipctest.IAIDLInterface interface,
     * generating a proxy if needed.
     */
    public static org.hrcy.ipctest.IAIDLInterface asInterface(android.os.IBinder obj)
    {
      if ((obj==null)) {
        return null;
      }
      android.os.IInterface iin = obj.queryLocalInterface(DESCRIPTOR);
      if (((iin!=null)&&(iin instanceof org.hrcy.ipctest.IAIDLInterface))) {
        return ((org.hrcy.ipctest.IAIDLInterface)iin);
      }
      return new org.hrcy.ipctest.IAIDLInterface.Stub.Proxy(obj);
    }
    @Override public android.os.IBinder asBinder()
    {
      return this;
    }
    @Override public boolean onTransact(int code, android.os.Parcel data, android.os.Parcel reply, int flags) throws android.os.RemoteException
    {
      java.lang.String descriptor = DESCRIPTOR;
      switch (code)
      {
        case INTERFACE_TRANSACTION:
        {
          reply.writeString(descriptor);
          return true;
        }
        case TRANSACTION_getStudent:
        {
          data.enforceInterface(descriptor);
          java.util.List<org.hrcy.ipctest.Student> _result = this.getStudent();
          reply.writeNoException();
          reply.writeTypedList(_result);
          return true;
        }
        case TRANSACTION_setStudent:
        {
          data.enforceInterface(descriptor);
          org.hrcy.ipctest.Student _arg0;
          if ((0!=data.readInt())) {
            _arg0 = org.hrcy.ipctest.Student.CREATOR.createFromParcel(data);
          }
          else {
            _arg0 = null;
          }
          this.setStudent(_arg0);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_sendRequest:
        {
          data.enforceInterface(descriptor);
          java.lang.String _arg0;
          _arg0 = data.readString();
          this.sendRequest(_arg0);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_sendShm:
        {
          data.enforceInterface(descriptor);
          android.os.SharedMemory _arg0;
          if ((0!=data.readInt())) {
            _arg0 = android.os.SharedMemory.CREATOR.createFromParcel(data);
          }
          else {
            _arg0 = null;
          }
          this.sendShm(_arg0);
          reply.writeNoException();
          return true;
        }
        default:
        {
          return super.onTransact(code, data, reply, flags);
        }
      }
    }
    private static class Proxy implements org.hrcy.ipctest.IAIDLInterface
    {
      private android.os.IBinder mRemote;
      Proxy(android.os.IBinder remote)
      {
        mRemote = remote;
      }
      @Override public android.os.IBinder asBinder()
      {
        return mRemote;
      }
      public java.lang.String getInterfaceDescriptor()
      {
        return DESCRIPTOR;
      }
      @Override public java.util.List<org.hrcy.ipctest.Student> getStudent() throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        java.util.List<org.hrcy.ipctest.Student> _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          boolean _status = mRemote.transact(Stub.TRANSACTION_getStudent, _data, _reply, 0);
          if (!_status && getDefaultImpl() != null) {
            return getDefaultImpl().getStudent();
          }
          _reply.readException();
          _result = _reply.createTypedArrayList(org.hrcy.ipctest.Student.CREATOR);
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
        return _result;
      }
      @Override public void setStudent(org.hrcy.ipctest.Student student) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          if ((student!=null)) {
            _data.writeInt(1);
            student.writeToParcel(_data, 0);
          }
          else {
            _data.writeInt(0);
          }
          boolean _status = mRemote.transact(Stub.TRANSACTION_setStudent, _data, _reply, 0);
          if (!_status && getDefaultImpl() != null) {
            getDefaultImpl().setStudent(student);
            return;
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void sendRequest(java.lang.String APIName) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeString(APIName);
          boolean _status = mRemote.transact(Stub.TRANSACTION_sendRequest, _data, _reply, 0);
          if (!_status && getDefaultImpl() != null) {
            getDefaultImpl().sendRequest(APIName);
            return;
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void sendShm(android.os.SharedMemory shm_object) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          if ((shm_object!=null)) {
            _data.writeInt(1);
            shm_object.writeToParcel(_data, 0);
          }
          else {
            _data.writeInt(0);
          }
          boolean _status = mRemote.transact(Stub.TRANSACTION_sendShm, _data, _reply, 0);
          if (!_status && getDefaultImpl() != null) {
            getDefaultImpl().sendShm(shm_object);
            return;
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      public static org.hrcy.ipctest.IAIDLInterface sDefaultImpl;
    }
    static final int TRANSACTION_getStudent = (android.os.IBinder.FIRST_CALL_TRANSACTION + 0);
    static final int TRANSACTION_setStudent = (android.os.IBinder.FIRST_CALL_TRANSACTION + 1);
    static final int TRANSACTION_sendRequest = (android.os.IBinder.FIRST_CALL_TRANSACTION + 2);
    static final int TRANSACTION_sendShm = (android.os.IBinder.FIRST_CALL_TRANSACTION + 3);
    public static boolean setDefaultImpl(org.hrcy.ipctest.IAIDLInterface impl) {
      if (Stub.Proxy.sDefaultImpl == null && impl != null) {
        Stub.Proxy.sDefaultImpl = impl;
        return true;
      }
      return false;
    }
    public static org.hrcy.ipctest.IAIDLInterface getDefaultImpl() {
      return Stub.Proxy.sDefaultImpl;
    }
  }
  public java.util.List<org.hrcy.ipctest.Student> getStudent() throws android.os.RemoteException;
  public void setStudent(org.hrcy.ipctest.Student student) throws android.os.RemoteException;
  public void sendRequest(java.lang.String APIName) throws android.os.RemoteException;
  public void sendShm(android.os.SharedMemory shm_object) throws android.os.RemoteException;
}
