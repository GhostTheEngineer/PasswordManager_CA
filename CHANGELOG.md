# **Changelog**  
This file contains information about the current version. To view past versions, please navigate through previous commits.  

## **Version 1.1.1**  
Fixed some 'bad practice' code related to how Encryption object was being passed into functions and removing an unnecessary heap allocation. Also, changed when the file extension is added in `custom_io`.

### **Additions**  
- None

---

### **Changes**  
- **`custom_io.cpp/h`:** 
    - The extension for the passwords file was being added to the filepath object in `SaveToFile` and `LoadFromFile` which forced us to not make the path object as a const parameter - this did not make sense. Now the `GetSavePath` includes the extension avoiding the checks in `SaveToFile` and `LoadFromFile` and thus making the parameters constants.
    - For the `SaveToFile` and `LoadFromFile` functions, the `IEncryption` is now passed as a const reference rather than raw pointer(actually was a reference to a pointer :/ )
- **`password_manager.cpp/h`:** the `CommitData` function now accepts a `IEncryption` const reference and we removed the class member of `IEncryption` and the argument from the constructor since it was pointless to be part of the class when it is only used in the `CommitData` function. 
- **`driver.cpp/h`:** reflects the above changes to pass in the encryption object as reference. This means we changed allocating on heap(don't know why we ever did so in first place) and allocated on stack - rather than assigning to the `IEncryption` object, we assign directly to the `HEXEncryption` object then pass that into respected functions which accept as the `IEncryption` interface to still work on the interface software design.

---

### **Fixes**  
- None
