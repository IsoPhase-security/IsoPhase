# Analyzed CVEs

## List of Analyzed CVEs

We conduct a brief study of all the publicly available CVEs related to data processing frameworks that IsoPhase supports.

| ID | CVE  | Vul. func./vari.  | Assoc. phases | Assoc. framework | Root cause|
|--| -----| --------------- | ------------------------------------ | ------------- | ---------------- | 
| 1  | [CVE-2019-5064](https://vulmon.com/vulnerabilitydetails?qid=CVE-2019-5064&scoretype=cvssv2)  | [CV\_FS\_MAX\_LEN](https://talosintelligence.com/vulnerability_reports/TALOS-2019-0853)| Phase 1 | OpenCV | Buffer Overflow |
| 2  | [CVE-2019-5063](https://vulmon.com/vulnerabilitydetails?qid=CVE-2019-5063&scoretype=cvssv2)       | [CV\_FS\_MAX\_LEN](https://talosintelligence.com/vulnerability_reports/TALOS-2019-0852) | Phase 1       | OpenCV| Buffer Overflow |
| 3  | [CVE-2019-14493](https://vulmon.com/vulnerabilitydetails?qid=CVE-2019-14493&scoretype=cvssv2)     | [cv::XMLParser::parse()](https://github.com/opencv/opencv/issues/15127)                    | Phase 1       | OpenCV           | null pointer deref             |
| 7  | [CVE-2018-5269](https://vulmon.com/vulnerabilitydetails?qid=CVE-2018-5269&scoretype=cvssv2)       | [cv::RBaseStream::setPos()](https://github.com/opencv/opencv/issues/10540)                 | Phase 1       | OpenCV           | DoS (assertion failure)        |
| 8  | [CVE-2018-5268](https://vulmon.com/vulnerabilitydetails?qid=CVE-2018-5268&scoretype=cvssv2)       | [cv::Jpeg2KDecoder::readComponent8u](https://github.com/opencv/opencv/blob/68d15fc62edad980f1ffa15ee478438335f39cc3/modules/imgcodecs/src/grfmt_jpeg2000.hpp)()                | Phase 1       | OpenCV           | Buffer Overflow                |
| 9  | [CVE-2017-18009](https://vulmon.com/vulnerabilitydetails?qid=CVE-2017-18009&scoretype=cvssv2)     | [cv::HdrDecoder::checkSignature](https://github.com/opencv/opencv/blob/68d15fc62edad980f1ffa15ee478438335f39cc3/modules/imgcodecs/src/grfmt_hdr.cpp)()    | Phase 1       | OpenCV           | OOB read  |
| 10 | [CVE-2017-17760](https://vulmon.com/vulnerabilitydetails?qid=CVE-2017-17760&scoretype=cvssv2)     | cv::PxMDecoder::readData() | Phase 1       | OpenCV           | Buffer Overflow                |
| 11 | [CVE-2017-14136](https://vulmon.com/vulnerabilitydetails?qid=CVE-2017-14136&scoretype=cvssv2)     | FillColorRow1()             | Phase 1       | OpenCV           | OOB write |
| 12 | [CVE-2017-12864](https://vulmon.com/vulnerabilitydetails?qid=CVE-2017-12864&scoretype=cvssv2)     | ReadNumber()                | Phase 1       | OpenCV           | OOB write |
| 13 | [CVE-2017-12863](https://vulmon.com/vulnerabilitydetails?qid=CVE-2017-12863&scoretype=cvssv2)     | PxMDecoder::readData()      | Phase 1       | OpenCV           | OOB write |
| 14 | [CVE-2017-12862](https://vulmon.com/vulnerabilitydetails?qid=CVE-2017-12862&scoretype=cvssv2)     | AutoBuffer                  | Phase 1       | OpenCV           | Buffer Overflow                |
| 15 | [CVE-2017-12606](https://vulmon.com/vulnerabilitydetails?qid=CVE-2017-12606&scoretype=cvssv2)     | FillColorRow4()| Phase 1       | OpenCV           | OOB write |
| 16 | [CVE-2017-12605](https://vulmon.com/vulnerabilitydetails?qid=CVE-2017-12605&scoretype=cvssv2)     | FillColorRow8()| Phase 1       | OpenCV           | OOB write |
| 17 | [CVE-2017-12604](https://vulmon.com/vulnerabilitydetails?qid=CVE-2017-12604&scoretype=cvssv2)     | FillUniColor()| Phase 1       | OpenCV           | OOB write |
| 18 | [CVE-2017-12603](https://vulmon.com/vulnerabilitydetails?qid=CVE-2017-12603&scoretype=cvssv2)     | cv::RLByteStream::getBytes()| Phase 1       | OpenCV           | Buffer Overflow                |
| 19 | [CVE-2017-12602](https://vulmon.com/vulnerabilitydetails?qid=CVE-2017-12602&scoretype=cvssv2)     | PxMDecoder::readData()     | Phase 1       | OpenCV           | DoS (memory consumption)       |
| 20 | [CVE-2017-12601](https://vulmon.com/vulnerabilitydetails?qid=CVE-2017-12601&scoretype=cvssv2)     | cv::BmpDecoder::readData()  | Phase 1       | OpenCV           | Buffer Overflow                |
| 21 | [CVE-2017-12600](https://vulmon.com/vulnerabilitydetails?qid=CVE-2017-12600&scoretype=cvssv2)     | PxMDecoder::readData() | Phase 1       | OpenCV           | DoS (CPU consumption)          |
| 22 | [CVE-2017-12599](https://vulmon.com/vulnerabilitydetails?qid=CVE-2017-12599&scoretype=cvssv2)     | icvCvt\_BGRA2BGR\_8u\_C4C3R()| Phase 1       | OpenCV           | OOB read  |
| 23 | [CVE-2017-12598](https://vulmon.com/vulnerabilitydetails?qid=CVE-2017-12598&scoretype=cvssv2)     | cv::RBaseStream::readBlock()| Phase 1       | OpenCV           | OOB read  |
| 24 | [CVE-2017-12597](https://vulmon.com/vulnerabilitydetails?qid=CVE-2017-12597&scoretype=cvssv2)     | FillColorRow1()    | Phase 1       | OpenCV           | Buffer Overflow (OOB write)    |
| 25 | [CVE-2017-1000450](https://vulmon.com/vulnerabilitydetails?qid=CVE-2017-1000450&scoretype=cvssv2) | FillUniColor() and FillUniGray()| Phase 1       | OpenCV           | Buffer Overflow (OOB write)    |
| 26 | [CVE-2016-1516](https://vulmon.com/vulnerabilitydetails?qid=CVE-2016-1516&scoretype=cvssv2)       | [faces.size( )](https://arxiv.org/pdf/1701.04739.pdf) | Phase 1       | OpenCV           | DoS (segfault)                 |
| 27 | [CVE-2016-1517](https://vulmon.com/vulnerabilitydetails?qid=CVE-2016-1517&scoretype=cvssv2)       | [faces.size( )](https://arxiv.org/pdf/1701.04739.pdf)  | Phase 1       | OpenCV           | DoS (segfault)                 |
| 28 | [CVE-2019-19624](https://vulmon.com/vulnerabilitydetails?qid=CVE-2019-19624&scoretype=cvssv2)     | [calc()](https://github.com/opencv/opencv/issues/14554)| Phase 2       | OpenCV           | OOB read  |
| 29 | [CVE-2019-15939](https://vulmon.com/vulnerabilitydetails?qid=CVE-2019-15939&scoretype=cvssv2)     | [cv::HOGDescriptor::getDescriptorSize](https://github.com/OpenCV/opencv/issues/15287)| Phase 2       | OpenCV           | divide-by-zero error           |
| 30 | [CVE-2019-14492](https://vulmon.com/vulnerabilitydetails?qid=CVE-2019-14492&scoretype=cvssv2)     | [HaarEvaluator::OptFeature::calc()](https://github.com/opencv/opencv/issues/15124) | Phase 2       | OpenCV           | OOB read/write                 |
| 31 | [CVE-2019-14491](https://vulmon.com/vulnerabilitydetails?qid=CVE-2019-14491&scoretype=cvssv2)     | [cv::predictOrdered<cv::HaarEvaluator>](https://github.com/opencv/opencv/issues/15125)  | Phase 2       | OpenCV           | OOB read  |
| 33 | [CVE-2017-12852](https://vulmon.com/vulnerabilitydetails?qid=CVE-2017-12852&scoretype=cvssv2)     | pad()  | Phase 2       | Numpy            | DoS (infinite loop)            |
| 34 | [CVE-2020-5313](https://vulmon.com/vulnerabilitydetails?qid=CVE-2020-5313&scoretype=cvssv2)       | [ImagingFliDecode()](https://github.com/python-pillow/Pillow/commit/a09acd0decd8a87ccce939d5ff65dab59e7d365b)  | Phase 1       | pillow           | Buffer Overflow (OOB write)    |
| 35 | [CVE-2020-5312](https://vulmon.com/vulnerabilitydetails?qid=CVE-2020-5312&scoretype=cvssv2)       | [ImagingPcxDecode()](https://github.com/python-pillow/Pillow/commit/93b22b846e0269ee9594ff71a72bec02d2bea8fd)   | Phase 1       | pillow           | Buffer Overflow                |
| 36 | [CVE-2020-5311](https://vulmon.com/vulnerabilitydetails?qid=CVE-2020-5311&scoretype=cvssv2)       | [expandrow()](https://github.com/python-pillow/Pillow/commit/a79b65c47c7dc6fe623aadf09aa6192fc54548f3)  | Phase 1       | pillow           | Buffer Overflow                |
| 37 | [CVE-2020-5310](https://vulmon.com/vulnerabilitydetails?qid=CVE-2020-5310&scoretype=cvssv2)       | [ImagingLibTiffDecode()](https://github.com/python-pillow/Pillow/commit/4e2def2539ec13e53a82e06c4b3daf00454100c4)| Phase 1       | pillow           | Buffer Overflow (OOB write)    |
| 38 | [CVE-2020-35655](https://vulmon.com/vulnerabilitydetails?qid=CVE-2020-35655&scoretype=cvssv2)     | [ImagingSgiRleDecode()](https://github.com/python-pillow/Pillow/commit/7e95c63fa7f503f185d3d9eb16b9cee1e54d1e46#)| Phase 1       | pillow           | Buffer Overflow (OOB read)     |
| 39 | [CVE-2020-35654](https://vulmon.com/vulnerabilitydetails?qid=CVE-2020-35654&scoretype=cvssv2)     | [\_decodeStripYCbCr()](https://github.com/python-pillow/Pillow/commit/eb8c1206d6b170d4e798a00db7432e023853da5c#)| Phase 1       | pillow           | Buffer Overflow (OOB write)    |
| 40 | [CVE-2020-35653](https://vulmon.com/vulnerabilitydetails?qid=CVE-2020-35653&scoretype=cvssv2)     | [ImagingPcxDecode()](https://github.com/python-pillow/Pillow/commit/6a83e4324738bb0452fbe8074a995b1c73f08de7#)| Phase 1       | pillow           | Buffer Overflow (OOB write)    |
| 42 | [CVE-2020-11538](https://vulmon.com/vulnerabilitydetails?qid=CVE-2020-11538&scoretype=cvssv2)     | [expandrow()](https://github.com/python-pillow/Pillow/commit/4853e522bddbec66022c0915b9a56255d0188bf9#diff-f68b69c1a25b9eb9788c2c848cc6752353d150f1e4e1bd068f041f6860de4337)  | Phase 1       | pillow           | OOB read  |
| 43 | [CVE-2020-10379](https://vulmon.com/vulnerabilitydetails?qid=CVE-2020-10379&scoretype=cvssv2)     | [ReadTile()](https://github.com/python-pillow/Pillow/commit/46f4a349b88915787fea3fb91348bb1665831bbb#diff-9478f2787e3ae9668a15123b165c23ac) | Phase 1       | pillow           | Buffer Overflow                |
| 44 | [CVE-2020-10378](https://vulmon.com/vulnerabilitydetails?qid=CVE-2020-10378&scoretype=cvssv2)     | [ImagingPcxDecode()](https://github.com/python-pillow/Pillow/commit/6a83e4324738bb0452fbe8074a995b1c73f08de7#)| Phase 1       | pillow           | OOB read  |
| 45 | [CVE-2020-10177](https://vulmon.com/vulnerabilitydetails?qid=CVE-2020-10177&scoretype=cvssv2)     | [ImagingFliDecode()](https://github.com/python-pillow/Pillow/pull/4503/commits/8d4f3c0c5f2fecf175aeb895e9c2d6d06d85bdc9)  | Phase 1       | pillow           | OOB read  |
| 46 | [CVE-2019-19911](https://vulmon.com/vulnerabilitydetails?qid=CVE-2019-19911&scoretype=cvssv2)     | [\_open\_index()](https://github.com/python-pillow/Pillow/commit/138bd714f5cb2346af71447f7ec52ed54037bc0b#) | Phase 1       | pillow           | DoS (OOB write)                |
| 47 | [CVE-2019-16865](https://vulmon.com/vulnerabilitydetails?qid=CVE-2019-16865&scoretype=cvssv2)     | [Image.getexif()](https://pillow.readthedocs.io/en/latest/releasenotes/6.2.0.html)    | Phase 1       | pillow           | DoS (OOB read)                 |
| 48 | [CVE-2016-9190](https://vulmon.com/vulnerabilitydetails?qid=CVE-2016-9190&scoretype=cvssv2)       | [ImagingNew()](https://github.com/python-pillow/Pillow/pull/2146/commits/5d8a0be45aad78c5a22c8d099118ee26ef8144af) | Phase 1       | pillow           | symlink attacks                |
| 49 | [CVE-2016-9189](https://vulmon.com/vulnerabilitydetails?qid=CVE-2016-9189&scoretype=cvssv2)       | [PyImaging\_MapBuffer()](https://github.com/python-pillow/Pillow/pull/2146/commits/c50ebe6459a131a1ea8ca531f10da616d3ceaa0f)| Phase 1       | pillow           | Buffer Overflow (OOB write)    |
| 50 | [CVE-2016-3076](https://vulmon.com/vulnerabilitydetails?qid=CVE-2016-3076&scoretype=cvssv2)       | [j2k\_encode\_entry()](https://github.com/python-pillow/Pillow/blob/ee079ae67e7e24ec789d3cc7d180820a70d32fe6/src/libImaging/Jpeg2KEncode.c) | Phase 1       | pillow           | Buffer Overflow (DOS(memory corruption))            |
| 51 | [CVE-2016-2533](https://vulmon.com/vulnerabilitydetails?qid=CVE-2016-2533&scoretype=cvssv2)       | [ImagingPcdDecode()](https://github.com/python-pillow/Pillow/commit/5bdf54b5a76b54fb00bd05f2d733e0a4173eefc9#diff-8ff6909c159597e22288ad818938fd6b)  | Phase 1       | pillow           | Buffer Overflow (DOS(crash))   |
| 52 | [CVE-2016-0775](https://vulmon.com/vulnerabilitydetails?qid=CVE-2016-0775&scoretype=cvssv2)       | [ImagingFliDecode()](https://github.com/python-pillow/Pillow/commit/893a40850c2d5da41537958e40569c029a6e127b)   | Phase 1       | pillow           | Buffer Overflow (DOS(crash))   |
| 53 | [CVE-2016-0740](https://vulmon.com/vulnerabilitydetails?qid=CVE-2016-0740&scoretype=cvssv2)       | [ImagingLibTiffDecode()](https://github.com/python-pillow/Pillow/commit/6dcbf5bd96b717c58d7b642949da8d323099928e)  | Phase 1       | pillow           | Buffer Overflow (OOB write)    |
| 54 | [CVE-2014-9601](https://vulmon.com/vulnerabilitydetails?qid=CVE-2014-9601&scoretype=cvssv2)       | [chunk\_iCCP()](https://github.com/python-pillow/Pillow/pull/1060/commits/44286ba3c9bfa6ed565d11bd61460d8ec215e1ea) | Phase 1       | pillow           | DoS (crash)                    |
| 55 | [CVE-2014-3598](https://vulmon.com/vulnerabilitydetails?qid=CVE-2014-3598&scoretype=cvssv2)       | [Jpeg2KImageFile()](https://github.com/python-pillow/Pillow/commit/d61921455e7e9d384dd93a783b459146c6a76d61#)  | Phase 1       | pillow           | DoS (crash)                    |
| 56 | [CVE-2014-3589](https://vulmon.com/vulnerabilitydetails?qid=CVE-2014-3589&scoretype=cvssv2)       | [\_\_init\_\_()](https://github.com/python-pillow/Pillow/commit/205e056f8f9b06ed7b925cf8aa0874bc4aaf8a7d) | Phase 1       | pillow           | DoS (crash)                    |
| 57 | [CVE-2014-3007](https://vulmon.com/vulnerabilitydetails?qid=CVE-2014-3007&scoretype=cvssv2)       | [load\_djpeg()](https://bugs.debian.org/cgi-bin/bugreport.cgi?bug=737059) | Phase 1       | pillow           | Buffer Overflow (OOB write)    |
| 58 | [CVE-2014-1933](https://vulmon.com/vulnerabilitydetails?qid=CVE-2014-1933&scoretype=cvssv2)       | [load\_djpeg() and Ghostscript()](https://github.com/python-pillow/Pillow/commit/4e9f367dfd3f04c8f5d23f7f759ec12782e10ee7)  | Phase 1       | pillow           | [Improper Link Resolution Before File Access (Symlink attacks)](https://capec.mitre.org/data/definitions/132.html) |
| 59 | [CVE-2014-1932](https://vulmon.com/vulnerabilitydetails?qid=CVE-2014-1932&scoretype=cvssv2)       | [load\_djpe(), Ghostscript(), load() amd \_copy()](https://github.com/python-pillow/Pillow/commit/4e9f367dfd3f04c8f5d23f7f759ec12782e10ee7) | Phase 1       | pillow           | [Improper Link Resolution Before File Access (Symlink attacks)](https://capec.mitre.org/data/definitions/132.html) |
| 60 | [CVE-2016-4009](https://vulmon.com/vulnerabilitydetails?qid=CVE-2016-4009&scoretype=cvssv2)       | [ImagingResampleHorizontal()](https://github.com/python-pillow/Pillow/commit/4e0d9b0b9740d258ade40cce248c93777362ac1e)  | Phase 2       | pillow           | Buffer Overflow (OOB write)    |
| 61 | [CVE-2020-26271](https://vulmon.com/vulnerabilitydetails?qid=CVE-2020-26271&scoretype=cvssv2)     | [GraphConstructor::MakeEdge()](https://github.com/tensorflow/tensorflow/commit/0cc38aaa4064fd9e79101994ce9872c6d91f816b)| Phase 1       | TensorFlow       | OOB read  |
| 62 | [CVE-2019-9635](https://vulmon.com/vulnerabilitydetails?qid=CVE-2019-9635&scoretype=cvssv2)       | [color\_map](https://github.com/tensorflow/tensorflow/commit/e41cb124cd0b325821af85cdacd9d8a12e206418) | Phase 1       | TensorFlow       | null pointer deref             |
| 63 | [CVE-2018-21233](https://vulmon.com/vulnerabilitydetails?qid=CVE-2018-21233&scoretype=cvssv2)     | [DecodeBmp](https://github.com/tensorflow/tensorflow/commit/49f73c55d56edffebde4bca4a407ad69c1cae433) | Phase 1       | TensorFlow       | OOB read  |
| 64 | [CVE-2018-7575](https://vulmon.com/vulnerabilitydetails?qid=CVE-2018-7575&scoretype=cvssv2)       | [kBlockTrailerSize](https://github.com/tensorflow/tensorflow/commit/d107fee1e4a9a4462f01564798d345802acc2aef)   | Phase 1       | TensorFlow       | OOB read  |
| 65 | [CVE-2018-7576](https://vulmon.com/vulnerabilitydetails?qid=CVE-2018-7576&scoretype=cvssv2)       | [GifErrorString()](https://github.com/tensorflow/tensorflow/commit/c48431588e7cf8aff61d4c299231e3e925144df8)  | Phase 1       | TensorFlow       | null pointer deref             |
| 66 | CVE-2020-5215 | [tf.float16](https://github.com/tensorflow/tensorflow/commit/5ac1b9e24ff6afc465756edf845d2e9660bd34bf) | Phase 2       | TensorFlow       | DoS (seg fault)                |
| 67 | [CVE-2020-26270](https://vulmon.com/vulnerabilitydetails?qid=CVE-2020-26270&scoretype=cvssv2)     | [CHECK\_GT()](https://github.com/tensorflow/tensorflow/commit/14755416e364f17fb1870882fa778c7fec7f16e3)| Phase 2       | TensorFlow       | OOB read  |
| 68 | [CVE-2020-26269](https://vulmon.com/vulnerabilitydetails?qid=CVE-2020-26269&scoretype=cvssv2)     | [GetMatchingPaths()](https://github.com/tensorflow/tensorflow/commit/8b5b9dc96666a3a5d27fad7179ff215e3b74b67c)| Phase 2       | TensorFlow       | OOB read  |
| 69 | [CVE-2020-26268](https://vulmon.com/vulnerabilitydetails?qid=CVE-2020-26268&scoretype=cvssv2)     | [tf.raw\_ops.ImmutableConst()](https://github.com/tensorflow/tensorflow/blob/5dcfc51118817f27fad5246812d83e5dccdc5f72/tensorflow/security/fuzzing/immutableConst_fuzz.py)       | Phase 2       | TensorFlow       | OOB write |
| 70 | [CVE-2020-26267](https://vulmon.com/vulnerabilitydetails?qid=CVE-2020-26267&scoretype=cvssv2)     | tf.raw\_ops.DataFormatVecPermute()  | Phase 2       | TensorFlow       | OOB read  |
| 71 | [CVE-2020-26266](https://vulmon.com/vulnerabilitydetails?qid=CVE-2020-26266&scoretype=cvssv2)     | [uninitialized QUInt8](https://github.com/tensorflow/tensorflow/commit/ace0c15a22f7f054abcc1f53eabbcb0a1239a9e2) | Phase 2       | TensorFlow       | uninitialized memory access    |
| 72 | [CVE-2020-15266](https://vulmon.com/vulnerabilitydetails?qid=CVE-2020-15266&scoretype=cvssv2)     | [tf.image.crop\_and\_resize.ParseAndCheckBoxSizes()](https://github.com/tensorflow/tensorflow/pull/42143/commits/3ade2efec2e90c6237de32a19680caaa3ebc2845)| Phase 2       | TensorFlow       | DoS (seg fault)                |
| 73 | [CVE-2020-15265](https://vulmon.com/vulnerabilitydetails?qid=CVE-2020-15265&scoretype=cvssv2)     | [tf.quantization.quantize\_and\_dequantize()](https://github.com/tensorflow/tensorflow/commit/eccb7ec454e6617738554a255d77f08e60ee0808)| Phase 2       | TensorFlow       | OOB read  |
| 74 | [CVE-2020-15206](https://vulmon.com/vulnerabilitydetails?qid=CVE-2020-15206&scoretype=cvssv2)     | [LoadSavedModel()](https://github.com/tensorflow/tensorflow/commit/adf095206f25471e864a8e63a0f1caef53a0e3a6)| Phase 2       | TensorFlow       | DoS (segfault)                 |
| 75 | [CVE-2020-15205](https://vulmon.com/vulnerabilitydetails?qid=CVE-2020-15205&scoretype=cvssv2)     | [tf.raw\_ops.StringNGrams()](https://github.com/tensorflow/tensorflow/commit/0462de5b544ed4731aa2fb23946ac22c01856b80) | Phase 2       | TensorFlow       | Buffer Overflow                |
| 76 | [CVE-2020-15204](https://vulmon.com/vulnerabilitydetails?qid=CVE-2020-15204&scoretype=cvssv2)     | [tf.raw\_ops.GetSessionHandle()](https://github.com/tensorflow/tensorflow/commit/9a133d73ae4b4664d22bd1aa6d654fec13c52ee1)| Phase 2       | TensorFlow       | null pointer deref             |
| 77 | [CVE-2020-15203](https://vulmon.com/vulnerabilitydetails?qid=CVE-2020-15203&scoretype=cvssv2)     | [tf.strings.as\_string()](https://github.com/tensorflow/tensorflow/commit/33be22c65d86256e6826666662e40dbdfe70ee83) | Phase 2       | TensorFlow       | Format string vul.             |
| 78 | [CVE-2020-15202](https://vulmon.com/vulnerabilitydetails?qid=CVE-2020-15203&scoretype=cvssv2)     | [Shard()](https://github.com/tensorflow/tensorflow/commit/ca8c013b5e97b1373b3bb1c97ea655e69f31a575) | Phase 2       | TensorFlow       | Format string vul.             |
| 79 | [CVE-2020-15201](https://vulmon.com/vulnerabilitydetails?qid=CVE-2020-15203&scoretype=cvssv2)     | [RaggedCountSparseOutput()](https://github.com/tensorflow/tensorflow/commit/3cbb917b4714766030b28eba9fb41bb97ce9ee02)  | Phase 2       | TensorFlow       | Buffer Overflow                |
| 80 | [CVE-2020-15200](https://vulmon.com/vulnerabilitydetails?qid=CVE-2020-15200&scoretype=cvssv2)     | [RaggedCountSparseOutput()](https://github.com/tensorflow/tensorflow/commit/3cbb917b4714766030b28eba9fb41bb97ce9ee02)| Phase 2       | TensorFlow       | Buffer Overflow                |
| 81 | [CVE-2020-15199](https://vulmon.com/vulnerabilitydetails?qid=CVE-2020-15199&scoretype=cvssv2)     | [RaggedCountSparseOutput()](https://github.com/tensorflow/tensorflow/commit/3cbb917b4714766030b28eba9fb41bb97ce9ee02)| Phase 2       | TensorFlow       | null pointer deref             |
| 82 | [CVE-2020-15198](https://vulmon.com/vulnerabilitydetails?qid=CVE-2020-15198&scoretype=cvssv2)     | [SparseCountSparseOutput()](https://github.com/tensorflow/tensorflow/commit/3cbb917b4714766030b28eba9fb41bb97ce9ee02)| Phase 2       | TensorFlow       | OOB read  |
| 83 | [CVE-2020-15197](https://vulmon.com/vulnerabilitydetails?qid=CVE-2020-15197&scoretype=cvssv2)     | [SparseCountSparseOutput()](https://github.com/tensorflow/tensorflow/commit/3cbb917b4714766030b28eba9fb41bb97ce9ee02)| Phase 2       | TensorFlow       | OOB write |
| 84 | [CVE-2020-15196](https://vulmon.com/vulnerabilitydetails?qid=CVE-2020-15196&scoretype=cvssv2)     | [SparseCountSparseOutput(), RaggedCountSparseOutput()](https://github.com/tensorflow/tensorflow/commit/3cbb917b4714766030b28eba9fb41bb97ce9ee02)  | Phase 2       | TensorFlow       | OOB read  |
| 85 | [CVE-2020-15195](https://vulmon.com/vulnerabilitydetails?qid=CVE-2020-15195&scoretype=cvssv2)     | [SparseFillEmptyRowsGrad()](https://github.com/tensorflow/tensorflow/commit/390611e0d45c5793c7066110af37c8514e6a6c54) | Phase 2       | TensorFlow       | Buffer Overflow                |
| 86 | [CVE-2020-15194](https://vulmon.com/vulnerabilitydetails?qid=CVE-2020-15194&scoretype=cvssv2)     | [SparseFillEmptyRowsGrad()](https://github.com/tensorflow/tensorflow/commit/390611e0d45c5793c7066110af37c8514e6a6c54) | Phase 2       | TensorFlow       | DoS (assertion failure)        |
| 87 | [CVE-2020-15193](https://vulmon.com/vulnerabilitydetails?qid=CVE-2020-15193&scoretype=cvssv2)     | [dlpack.to\_dlpack()](https://github.com/tensorflow/tensorflow/commit/22e07fb204386768e5bcbea563641ea11f96ceb8)| Phase 2       | TensorFlow       | memory corruption              |
| 88 | [CVE-2020-15192](https://vulmon.com/vulnerabilitydetails?qid=CVE-2020-15192&scoretype=cvssv2)     | [dlpack.to\_dlpack()](https://github.com/tensorflow/tensorflow/commit/22e07fb204386768e5bcbea563641ea11f96ceb8)| Phase 2       | TensorFlow       | DoS (seg fault)                |
| 89 | [CVE-2020-15191](https://vulmon.com/vulnerabilitydetails?qid=CVE-2020-15191&scoretype=cvssv2)     | [dlpack.to\_dlpack()](https://github.com/tensorflow/tensorflow/commit/22e07fb204386768e5bcbea563641ea11f96ceb8)| Phase 2       | TensorFlow       | null pointer deref             |
| 90 | [CVE-2020-15190](https://vulmon.com/vulnerabilitydetails?qid=CVE-2020-15190&scoretype=cvssv2)     | [tf.raw\_ops.Switch()](https://github.com/tensorflow/tensorflow/commit/da8558533d925694483d2c136a9220d6d49d843c)| Phase 2       | TensorFlow       | null pointer deref             |
| 91 | [CVE-2019-16778](https://vulmon.com/vulnerabilitydetails?qid=CVE-2019-16778&scoretype=cvssv2)     | [num\_segments](https://github.com/tensorflow/tensorflow/commit/db4f9717c41bccc3ce10099ab61996b246099892)| Phase 2       | TensorFlow       | Buffer Overflow                |
| 1  | [CVE-2019-9423](https://vulmon.com/vulnerabilitydetails?qid=CVE-2019-9423&scoretype=cvssv2)       |  Android  | Phase 2| OpenCV           | OOB read  |
| 2  | [CVE-2019-16249](https://vulmon.com/vulnerabilitydetails?qid=CVE-2019-16249&scoretype=cvssv2)     | [v\_load](https://github.com/opencv/opencv/blob/master/modules/core/include/opencv2/core/hal/intrin_sse.hpp)  | Phase 2       | OpenCV           | OOB read  |
| 5  | [CVE-2016-10658](https://vulmon.com/vulnerabilitydetails?qid=CVE-2016-10658&scoretype=cvssv2)     | [dll\_files: function](https://github.com/BloodAxe/npm-native-opencv/blob/master/opencv.js)| Phase 1       | OpenCV           | MITM attack                    |
| 7  | [CVE-2014-1858](https://vulmon.com/vulnerabilitydetails?qid=CVE-2014-1858&scoretype=cvssv2)       | [compile()](https://github.com/numpy/numpy/commit/0bb46c1448b0d3f5453d5182a17ea7ac5854ee15) | Phase 1       | Numpy            | Arbitrary file writes (symlink attack)              |
| 8  | [CVE-2014-1859](https://vulmon.com/vulnerabilitydetails?qid=CVE-2014-1859&scoretype=cvssv2)       | [test\_open\_with\_filename()](https://git01lab.cs.univie.ac.at/karynav98/meen/-/blob/e01310384b36cd8b5fb2aabf34b0cdad9373f04c/venv/lib/python3.7/site-packages/numpy/core/tests/test_memmap.py)    | Phase 1       | Numpy            | Arbitrary file writes (symlink attack)              |
| 9  | [CVE-2021-25289](https://vulmon.com/vulnerabilitydetails?qid=CVE-2021-25289&scoretype=cvssv2)     | [ImagingLibTiffDecode()](https://github.com/python-pillow/Pillow/blob/master/src/libImaging/TiffDecode.c)   | Phase 2       | pillow           | Buffer Overflow                |
| 10 | [CVE-2021-25290](https://vulmon.com/vulnerabilitydetails?qid=CVE-2021-25290&scoretype=cvssv2)     | TiffDecode.c| Phase 2       | pillow           | DoS (seg fault)                |
| 11 | [CVE-2021-25291](https://vulmon.com/vulnerabilitydetails?qid=CVE-2021-25291&scoretype=cvssv2)     | [TiffreadRGBATile()](https://github.com/python-pillow/Pillow/commit/cbdce6c5d054fccaf4af34b47f212355c64ace7a#diff-c14dc7d9af4fe076243626b59ced670427ab44b3db691e70f7a6ae0b2cc76264)                | Phase 2       | pillow           | OOB read  |
| 12 | [CVE-2021-25292](https://vulmon.com/vulnerabilitydetails?qid=CVE-2021-25292&scoretype=cvssv2)     | [read\_pdf\_info(](https://github.com/python-pillow/Pillow/commit/3bce145966374dd39ce58a6fc0083f8d1890719c))  | Phase 1       | pillow           | DoS (ReDos)                    |
| 13 | [CVE-2021-25293](https://vulmon.com/vulnerabilitydetails?qid=CVE-2021-25293&scoretype=cvssv2)     | [expandrow()](https://github.com/python-pillow/Pillow/commit/4853e522bddbec66022c0915b9a56255d0188bf9#)   | Phase 2       | pillow           | OOB read  |
| 14 | [CVE-2021-27923](https://vulmon.com/vulnerabilitydetails?qid=CVE-2021-27923&scoretype=cvssv2)     | [PngImagePlugin.PngImageFile()](https://github.com/python-pillow/Pillow/commit/480f6819b592d7f07b9a9a52a7656c10bbe07442#diff-36db343209bdaf8bca08841a8d03f4daac59c37afe6f6d1aee6b7e8fd116fd88) | Phase 1       | pillow           | DoS (OOB write)                |
| 15 | [CVE-2021-27922](https://vulmon.com/vulnerabilitydetails?qid=CVE-2021-27922&scoretype=cvssv2)     | [Jpeg2KImagePlugin.Jpeg2KImageFile(](https://github.com/python-pillow/Pillow/commit/480f6819b592d7f07b9a9a52a7656c10bbe07442#diff-36db343209bdaf8bca08841a8d03f4daac59c37afe6f6d1aee6b7e8fd116fd88)  | Phase 1       | pillow           | DoS (OOB write)                |
| 16 | [CVE-2021-27921](https://vulmon.com/vulnerabilitydetails?qid=CVE-2021-27921&scoretype=cvssv2)     | [JpegImageFile(](https://github.com/python-pillow/Pillow/commit/480f6819b592d7f07b9a9a52a7656c10bbe07442#diff-36db343209bdaf8bca08841a8d03f4daac59c37afe6f6d1aee6b7e8fd116fd88))  | Phase 1       | pillow           | DoS (OOB write)                |
| 17 | [CVE-2020-10994](https://vulmon.com/vulnerabilitydetails?qid=CVE-2020-10994&scoretype=cvssv2)     | [j2k\_decode\_entry()](https://github.com/python-pillow/Pillow/commit/cf6da6b79080a8c16984102fdc85f7ce28dca613#diff-86cd7a0c43a170b8d4867aaa6ff574a559ce101e2e6d8493151ebb5f3d62d0ff)    | Phase 1       | pillow           | OOB read  |
| 18 | [CVE-2020-15214](https://vulmon.com/vulnerabilitydetails?qid=CVE-2020-15214&scoretype=cvssv2)     | [Verifier()](https://github.com/InES-HPMM/Artificial_Intelligence_on_Microcontrollers/blob/21c819eac1b7cb8bf9bda1094783cbbd8a29f130/frameworks/tfLite/tensorflow/lite/model_test.cc)                | Phase 2       | TensorFlow       | OOB write |
| 19 | [CVE-2020-15213](https://vulmon.com/vulnerabilitydetails?qid=CVE-2020-15213&scoretype=cvssv2)     | [Verifier()](https://github.com/InES-HPMM/Artificial_Intelligence_on_Microcontrollers/blob/21c819eac1b7cb8bf9bda1094783cbbd8a29f130/frameworks/tfLite/tensorflow/lite/model_test.cc)                 | Phase 2       | TensorFlow       | DoS (OOB read)                 |
| 20 | [CVE-2020-15208](https://vulmon.com/vulnerabilitydetails?qid=CVE-2020-15208&scoretype=cvssv2)     | [TFLITE\_DCHECK()](https://github.com/tensorflow/tensorflow/commit/8ee24e7949a203d234489f9da2c5bf45a7d5157d)  | Phase 2       | TensorFlow       | OOB read/write                 |
| 21 | [CVE-2020-15209](https://vulmon.com/vulnerabilitydetails?qid=CVE-2020-15209&scoretype=cvssv2)     | [nullptr](https://github.com/tensorflow/tensorflow/security/advisories/GHSA-qh32-6jjc-qprm)| Phase 2       | TensorFlow       | DoS (null pointer deref)       |
| 22 | [CVE-2020-15211](https://vulmon.com/vulnerabilitydetails?qid=CVE-2020-15211&scoretype=cvssv2)     | [flatbuffer](https://github.com/tensorflow/tensorflow/security/advisories/GHSA-cvpc-8phh-8f45)    | Phase 2       | TensorFlow       | OOB read  |
| 23 | [CVE-2020-15210](https://vulmon.com/vulnerabilitydetails?qid=CVE-2020-15210&scoretype=cvssv2)      | TFLite      | Phase 2       | TensorFlow       | DoS (seg fault)                |
| 24 | [CVE-2020-15212](https://vulmon.com/vulnerabilitydetails?qid=CVE-2020-15212&scoretype=cvssv2)     | [segment\_ids\_data](https://github.com/tensorflow/tensorflow/security/advisories/GHSA-hx2x-85gr-wrpq)   | Phase 2       | TensorFlow       | OOB write |
| 25 | [CVE-2020-15207](https://vulmon.com/vulnerabilitydetails?qid=CVE-2020-15207&scoretype=cvssv2)     | [ResolveAxis](https://github.com/tensorflow/tensorflow/commit/2d88f470dea2671b430884260f3626b1fe99830a) | Phase 2       | TensorFlow       | OOB read  |
| 27 | [CVE-2018-10055](https://vulmon.com/vulnerabilitydetails?qid=CVE-2018-10055&scoretype=cvssv2)     | [info.data\_type](https://github.com/tensorflow/tensorflow/blob/master/tensorflow/security/advisory/tfsa-2018-006.md)   | Phase 2       | TensorFlow       | Buffer Overflow (OOB read)     |
| 28 | [CVE-2018-8825](https://vulmon.com/vulnerabilitydetails?qid=CVE-2018-8825&scoretype=cvssv2)       | [toco](https://github.com/tensorflow/tensorflow/commit/41335abb46f80ca644b5738550daef6136ba5476)  | Phase 2       | TensorFlow       | Buffer Overflow                |
| 29 | [CVE-2018-7577](https://vulmon.com/vulnerabilitydetails?qid=CVE-2018-7577&scoretype=cvssv2)       | [genrule.cmd](https://github.com/tensorflow/tensorflow/commit/dfa9921e6343727b05f42f8d4a918b19528ff994)  | Phase 1       | TensorFlow       | OOB read  |

| Phase   | OpenCV           | Numpy          | Pillow         | TensorFlow     | PyTorch | Caffe |
| ------- | ---------------- | -------------- | -------------- | -------------- | ------- | ----- |
| Phase1  | CVE-2019-5064    | CVE-2019-6446  | CVE-2021-25292 | CVE-2020-26271 | N/A     | N/A   |
|         | CVE-2019-5063    | CVE-2014-1858  | CVE-2021-27923 | CVE-2019-9635  |         |       |
|         | CVE-2019-14493   | CVE-2014-1859  | CVE-2021-27922 | CVE-2018-21233 |         |       |
|         | CVE-2018-7714    |                | CVE-2021-27921 | CVE-2018-7575  |         |       |
|         | CVE-2018-7713    |                | CVE-2020-10994 | CVE-2018-7576  |         |       |
|         | CVE-2018-7712    |                | CVE-2020-5313  | CVE-2018-7577  |         |       |
|         | CVE-2018-5269    |                | CVE-2020-5312  |                |         |       |
|         | CVE-2018-5268    |                | CVE-2020-5311  |                |         |       |
|         | CVE-2017-18009   |                | CVE-2020-5310  |                |         |       |
|         | CVE-2017-17760   |                | CVE-2020-35655 |                |         |       |
|         | CVE-2017-14136   |                | CVE-2020-35654 |                |         |       |
|         | CVE-2017-12864   |                | CVE-2020-35653 |                |         |       |
|         | CVE-2017-12863   |                | CVE-2020-11538 |                |         |       |
|         | CVE-2017-12862   |                | CVE-2020-11538 |                |         |       |
|         | CVE-2017-12606   |                | CVE-2020-10379 |                |         |       |
|         | CVE-2017-12605   |                | CVE-2020-10378 |                |         |       |
|         | CVE-2017-12604   |                | CVE-2020-10177 |                |         |       |
|         | CVE-2017-12603   |                | CVE-2019-19911 |                |         |       |
|         | CVE-2017-12602   |                | CVE-2019-16865 |                |         |       |
|         | CVE-2017-12601   |                | CVE-2016-9190  |                |         |       |
|         | CVE-2017-12600   |                | CVE-2016-9189  |                |         |       |
|         | CVE-2017-12599   |                | CVE-2016-3076  |                |         |       |
|         | CVE-2017-12598   |                | CVE-2016-2533  |                |         |       |
|         | CVE-2017-12597   |                | CVE-2016-0775  |                |         |       |
|         | CVE-2017-1000450 |                | CVE-2016-0740  |                |         |       |
|         | CVE-2016-1516    |                | CVE-2014-9601  |                |         |       |
|         | CVE-2016-1517    |                | CVE-2014-3598  |                |         |       |
|         | CVE-2016-10658   |                | CVE-2014-3589  |                |         |       |
|         |                  |                | CVE-2014-3007  |                |         |       |
|         |                  |                | CVE-2014-1933  |                |         |       |
|         |                  |                | CVE-2014-1932  |                |         |       |
| Phase 2 | CVE-2019-19624   | CVE-2017-12852 | CVE-2016-4009  | CVE-2020-5215  | N/A     | N/A   |
|         | CVE-2019-15939   |                | CVE-2021-25289 | CVE-2020-26270 |         |       |
|         | CVE-2019-14492   |                | CVE-2021-25290 | CVE-2020-26269 |         |       |
|         | CVE-2019-14491   |                | CVE-2021-25291 | CVE-2020-26268 |         |       |
|         | CVE-2019-16249   |                | CVE-2021-25293 | CVE-2020-26267 |         |       |
|         |                  |                |                | CVE-2020-26266 |         |       |
|         |                  |                |                | CVE-2020-15266 |         |       |
|         |                  |                |                | CVE-2020-15265 |         |       |
|         |                  |                |                | CVE-2020-15206 |         |       |
|         |                  |                |                | CVE-2020-15205 |         |       |
|         |                  |                |                | CVE-2020-15204 |         |       |
|         |                  |                |                | CVE-2020-15203 |         |       |
|         |                  |                |                | CVE-2020-15202 |         |       |
|         |                  |                |                | CVE-2020-15201 |         |       |
|         |                  |                |                | CVE-2020-15200 |         |       |
|         |                  |                |                | CVE-2020-15199 |         |       |
|         |                  |                |                | CVE-2020-15198 |         |       |
|         |                  |                |                | CVE-2020-15197 |         |       |
|         |                  |                |                | CVE-2020-15196 |         |       |
|         |                  |                |                | CVE-2020-15195 |         |       |
|         |                  |                |                | CVE-2020-15194 |         |       |
|         |                  |                |                | CVE-2020-15193 |         |       |
|         |                  |                |                | CVE-2020-15192 |         |       |
|         |                  |                |                | CVE-2020-15191 |         |       |
|         |                  |                |                | CVE-2020-15190 |         |       |
|         |                  |                |                | CVE-2019-16778 |         |       |
|         |                  |                |                | CVE-2018-21233 |         |       |
|         |                  |                |                | CVE-2020-15214 |         |       |
|         |                  |                |                | CVE-2020-15213 |         |       |
|         |                  |                |                | CVE-2020-15208 |         |       |
|         |                  |                |                | CVE-2020-15209 |         |       |
|         |                  |                |                | CVE-2020-15211 |         |       |
|         |                  |                |                | CVE-2020-15210 |         |       |
|         |                  |                |                | CVE-2020-15212 |         |       |
|         |                  |                |                | CVE-2020-15207 |         |       |
|         |                  |                |                | CVE-2018-10055 |         |       |
|         |                  |                |                | CVE-2018-8825  |         |       |
| Phase 3 | N/A              | N/A            | N/A            | N/A            | N/A     | N/A   |
| Phase 4 | N/A              | N/A            | N/A            | N/A            | N/A     | N/A   |
# Analyzed Applications

We searched popular applications under topic OpenCV, PyTorch, Caffe and TensorFlow. The popularity is measured by the number of stars.

We manually inspect the source code of these projects and find those popular deep learning framework based applications do not break the assumptions on the pipline data flow pattern.

## List of Applications and Security-sensitive Data

We identify four types of security-sensitive data (S<sub>1</sub> ~ S<sub>4</sub>).

| Symbol        | Sensitive Information                                             |
| ------------- | ----------------------------------------------------------------- |
| S<sub>1</sub> | Detected values of detected faces/objects/emotions from the input |
| S<sub>2</sub> | Outputs annotated with the results and sensitive information      |
| S<sub>3</sub> | Sensitive metadata that the program loads                         |
| S<sub>4</sub> | ML models and their configurations                                |

In below table, the third ~ fifth column show the sensitive data types each program includes, which we define as above.

| Framework  | Name                             | Phase 1 | Phase 2                      | Phase 3                      | Phase 4 | Source Code                                                             |
| ---------- | -------------------------------- | ------- | ---------------------------- | ---------------------------- | ------- | ----------------------------------------------------------------------- |
| OpenCV     | Face_Recognition                 | None    | S<sub>1</sub>, S<sub>4</sub> | S<sub>2</sub>, S<sub>3</sub> | None    | [Link](https://github.com/ageitgey/face_recognition)                    |
| OpenCV     | faceai                           | None    | S<sub>1</sub>, S<sub>4</sub> | S<sub>2</sub>                | None    | [Link](https://github.com/vipstone/faceai)                              |
| OpenCV     | BossSensor                       | None    | S<sub>1</sub>, S<sub>4</sub> | S<sub>2</sub>                | None    | [Link](https://github.com/Hironsan/BossSensor)                          |
| OpenCV     | tiler                            | None    | S<sub>1</sub>, S<sub>4</sub> | S<sub>2</sub>                | None    | [Link](https://github.com/nuno-faria/tiler)                             |
| OpenCV     | sistine                          | None    | S<sub>1</sub>, S<sub>4</sub> | S<sub>2</sub>                | None    | [Link](https://github.com/bijection/sistine)                            |
| OpenCV     | trace.moe                        | None    | S<sub>1</sub>, S<sub>4</sub> | S<sub>2</sub>, S<sub>3</sub> | None    | [Link](https://github.com/soruly/trace.moe)                             |
| OpenCV     | mathAI                           | None    | S<sub>1</sub>, S<sub>4</sub> | S<sub>2</sub>                | None    | [Link](https://github.com/Roujack/mathAI)                               |
| OpenCV     | Is-Now-Illegal                   | None    | S<sub>1</sub>, S<sub>4</sub> | S<sub>2</sub>, S<sub>3</sub> | None    | [Link](https://github.com/ivanseidel/Is-Now-Illegal)                    |
| OpenCV     | video-to-ascii                   | None    | S<sub>1</sub>, S<sub>4</sub> | S<sub>2</sub>                | None    | [Link](https://github.com/joelibaceta/video-to-ascii)                   |
| OpenCV     | DeepNude_NoWatermark_withModel   | None    | S<sub>1</sub>, S<sub>4</sub> | S<sub>2</sub>                | None    | [Link](https://github.com/zhengyima/DeepNude_NoWatermark_withModel)     |
| OpenCV     | idcardgenerator                  | None    | S<sub>1</sub>, S<sub>4</sub> | S<sub>2</sub>                | None    | [Link](https://github.com/airob0t/idcardgenerator)                      |
| OpenCV     | eyeLike                          | None    | S<sub>1</sub>, S<sub>4</sub> | S<sub>2</sub>                | None    | [Link](https://github.com/trishume/eyeLike)                             |
| OpenCV     | Anime-InPainting                 | None    | S<sub>1</sub>, S<sub>4</sub> | S<sub>2</sub>                | None    | [Link](https://github.com/youyuge34/Anime-InPainting)                   |
| OpenCV     | lbpcascade_animeface             | None    | S<sub>1</sub>, S<sub>4</sub> | S<sub>2</sub>                | None    | [Link](https://github.com/nagadomi/lbpcascade_animeface)                |
| OpenCV     | captcha-break                    | None    | S<sub>1</sub>, S<sub>4</sub> | S<sub>2</sub>, S<sub>3</sub> | None    | [Link](https://github.com/nladuo/captcha-break)                         |
| OpenCV     | vehicle_detection                | None    | S<sub>1</sub>, S<sub>4</sub> | S<sub>2</sub>                | None    | [Link](https://github.com/tatsuyah/vehicle-detection)                   |
| PyTorch    | Real-Time-Voice-Cloning          | None    | S<sub>1</sub>, S<sub>4</sub> | S<sub>2</sub>                | None    | [Link](https://github.com/CorentinJ/Real-Time-Voice-Cloning)            |
| PyTorch    | pytorch-CycleGAN-and-pix2pix     | None    | S<sub>1</sub>, S<sub>4</sub> | S<sub>2</sub>                | None    | [Link](https://github.com/junyanz/pytorch-CycleGAN-and-pix2pix)         |
| PyTorch    | mmdetection                      | None    | S<sub>1</sub>, S<sub>4</sub> | S<sub>2</sub>                | None    | [Link](https://github.com/open-mmlab/mmdetection)                       |
| PyTorch    | fairseq                          | None    | S<sub>1</sub>, S<sub>4</sub> | S<sub>2</sub>                | None    | [Link](https://github.com/pytorch/fairseq)                              |
| PyTorch    | EasyOCR                          | None    | S<sub>1</sub>, S<sub>4</sub> | S<sub>2</sub>, S<sub>3</sub> | None    | [Link](https://github.com/JaidedAI/EasyOCR)                             |
| PyTorch    | yolov5                           | None    | S<sub>1</sub>, S<sub>4</sub> | S<sub>2</sub>                | None    | [Link](https://github.com/ultralytics/yolov5)                           |
| PyTorch    | Bringing-Old-Photos-Back-to-Life | None    | S<sub>1</sub>, S<sub>4</sub> | S<sub>2</sub>                | None    | [Link](https://github.com/microsoft/Bringing-Old-Photos-Back-to-Life)   |
| PyTorch    | yolov3                           | None    | S<sub>1</sub>, S<sub>4</sub> | S<sub>2</sub>                | None    | [Link](https://github.com/ultralytics/yolov3)                           |
| PyTorch    | chineseocr_lite                  | None    | S<sub>1</sub>, S<sub>4</sub> | S<sub>2</sub>                | None    | [Link](https://github.com/ouyanghuiyu/chineseocr_lite)                  |
| PyTorch    | pix2pixHD                        | None    | S<sub>1</sub>, S<sub>4</sub> | S<sub>2</sub>                | None    | [Link](https://github.com/NVIDIA/pix2pixHD)                             |
| PyTorch    | stargan                          | None    | S<sub>1</sub>, S<sub>4</sub> | S<sub>2</sub>                | None    | [Link](https://github.com/yunjey/stargan)                               |
| PyTorch    | SiamMask                         | None    | S<sub>1</sub>, S<sub>4</sub> | S<sub>2</sub>                | None    | [Link](https://github.com/foolwood/SiamMask)                            |
| PyTorch    | Pytorch-UNet                     | None    | S<sub>1</sub>, S<sub>4</sub> | S<sub>2</sub>                | None    | [Link](https://github.com/milesial/Pytorch-UNet)                        |
| PyTorch    | EfficientNet-PyTorch             | None    | S<sub>1</sub>, S<sub>4</sub> | S<sub>2</sub>                | None    | [Link](https://github.com/lukemelas/EfficientNet-PyTorch)               |
| PyTorch    | Semantic-Segmentation            | None    | S<sub>1</sub>, S<sub>4</sub> | S<sub>2</sub>                | None    | [Link](https://github.com/CSAILVision/semantic-segmentation-pytorch)    |
| TensorFlow | Real-Time-Voice-Cloning          | None    | S<sub>1</sub>, S<sub>4</sub> | S<sub>2</sub>                | None    | [Link](https://github.com/CorentinJ/Real-Time-Voice-Cloning)            |
| TensorFlow | DeepSpeech                       | None    | S<sub>1</sub>, S<sub>4</sub> | S<sub>2</sub>                | None    | [Link](https://github.com/mozilla/DeepSpeech)                           |
| TensorFlow | facenet                          | None    | S<sub>1</sub>, S<sub>4</sub> | S<sub>2</sub>                | None    | [Link](https://github.com/davidsandberg/facenet)                        |
| TensorFlow | DeepCreamPy                      | None    | S<sub>1</sub>, S<sub>4</sub> | S<sub>2</sub>                | None    | [Link](https://github.com/deeppomf/DeepCreamPy)                         |
| TensorFlow | Learning-to-See-in-the-Dark      | None    | S<sub>1</sub>, S<sub>4</sub> | S<sub>2</sub>                | None    | [Link](https://github.com/cchen156/Learning-to-See-in-the-Dark)         |
| TensorFlow | tf-pose-estimation               | None    | S<sub>1</sub>, S<sub>4</sub> | S<sub>2</sub>                | None    | [Link](https://github.com/ildoonet/tf-pose-estimation)                  |
| TensorFlow | CapsNet-Tensorflow               | None    | S<sub>1</sub>, S<sub>4</sub> | S<sub>2</sub>                | None    | [Link](https://github.com/naturomics/CapsNet-Tensorflow)                |
| TensorFlow | text-classification-cnn-rnn      | None    | S<sub>1</sub>, S<sub>4</sub> | S<sub>2</sub>                | None    | [Link](https://github.com/gaussic/text-classification-cnn-rnn)          |
| TensorFlow | tensorflow-yolov3                | None    | S<sub>1</sub>, S<sub>4</sub> | S<sub>2</sub>                | None    | [Link](https://github.com/YunYang1994/tensorflow-yolov3)                |
| TensorFlow | tensorflow_poems                 | None    | S<sub>1</sub>, S<sub>4</sub> | S<sub>2</sub>                | None    | [Link](https://github.com/jinfagang/tensorflow_poems)                   |
| TensorFlow | Automatic_Speech_Recognition     | None    | S<sub>1</sub>, S<sub>4</sub> | S<sub>2</sub>                | None    | [Link](https://github.com/zzw922cn/Automatic_Speech_Recognition)        |
| TensorFlow | AnimeGAN                         | None    | S<sub>1</sub>, S<sub>4</sub> | S<sub>2</sub>                | None    | [Link](https://github.com/TachibanaYoshino/AnimeGAN)                    |
| TensorFlow | srgan                            | None    | S<sub>1</sub>, S<sub>4</sub> | S<sub>2</sub>                | None    | [Link](https://github.com/tensorlayer/srgan)                            |
| TensorFlow | DCGAN-TensorFlow                 | None    | S<sub>1</sub>, S<sub>4</sub> | S<sub>2</sub>                | None    | [Link](https://github.com/carpedm20/DCGAN-tensorflow)                   |
| TensorFlow | Style-Transfer                   | None    | S<sub>1</sub>, S<sub>4</sub> | S<sub>2</sub>                | None    | [Link](https://github.com/lengstrom/fast-style-transfer)                |
| Caffe      | openpose                         | None    | S<sub>1</sub>, S<sub>4</sub> | S<sub>2</sub>                | None    | [Link](https://github.com/CMU-Perceptual-Computing-Lab/openpose)        |
| Caffe      | MobileNet-SSD                    | None    | S<sub>1</sub>, S<sub>4</sub> | S<sub>2</sub>                | None    | [Link](https://github.com/chuanqi305/MobileNet-SSD)                     |
| Caffe      | EmoRecon                         | None    | S<sub>1</sub>, S<sub>4</sub> | S<sub>2</sub>                | None    | [Link](https://github.com/sushant3095/RealtimeFacialEmotionRecognition) |
| Caffe      | MTCNN                            | None    | S<sub>1</sub>, S<sub>4</sub> | S<sub>2</sub>                | None    | [Link](https://github.com/CongWeilin/mtcnn-caffe)                       |
| Caffe      | FaceMaskDetection                | None    | S<sub>1</sub>, S<sub>4</sub> | S<sub>2</sub>                | None    | [Link](https://github.com/AIZOOTech/FaceMaskDetection)                  |
| Caffe      | face_verification                | None    | S<sub>1</sub>, S<sub>4</sub> | S<sub>2</sub>, S<sub>3</sub> | None    | [Link](https://github.com/AlfredXiangWu/face_verification_experiment)   |
| Caffe      | Face-Mask-Detection              | None    | S<sub>1</sub>, S<sub>4</sub> | S<sub>2</sub>                | None    | [Link](https://github.com/chandrikadeb7/Face-Mask-Detection)            |
| Caffe      | person_search                    | None    | S<sub>1</sub>, S<sub>4</sub> | S<sub>2</sub>, S<sub>3</sub> | None    | [Link](https://github.com/ShuangLI59/person_search)                     |
| Caffe      | multi-object-tracker             | None    | S<sub>1</sub>, S<sub>4</sub> | S<sub>2</sub>                | None    | [Link](https://github.com/adipandas/multi-object-tracker)               |
| Caffe      | caffe-yolov3                     | None    | S<sub>1</sub>, S<sub>4</sub> | S<sub>2</sub>                | None    | [Link](https://github.com/ChenYingpeng/caffe-yolov3)                    |
