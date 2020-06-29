using System;
using System.Collections.Generic;
using System.Drawing;
using System.Drawing.Imaging;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows;

/// <summary>
/// 画像処理のロジック
/// </summary>
namespace ImageProcessing
{
    class ImageProcessing : ComImageProcessing
    {
        private readonly Object[] array = new object[(int)ComInfo.ImgProcType.MAX];

        /// <summary>
        /// 閾値
        /// </summary>
        public byte Thresh { set; get; }

        /// <summary>
        /// コンストラクタ
        /// </summary>
        /// <param name="bitmap">ビットマップ</param>
        public ImageProcessing(Bitmap bitmap) : base(bitmap)
        {
            var edgeDetection = new EdgeDetection();
            array[(int)ComInfo.ImgProcType.EdgeDetection] = edgeDetection;
            var grayScale = new GrayScale();
            array[(int)ComInfo.ImgProcType.GrayScale] = grayScale;
            var binarization = new Binarization();
            array[(int)ComInfo.ImgProcType.Binarization] = binarization;
            var grayScale2Diff = new GrayScale2Diff();
            array[(int)ComInfo.ImgProcType.GrayScale2Diff] = grayScale2Diff;
            var colorReversal = new ColorReversal();
            array[(int)ComInfo.ImgProcType.ColorReversal] = colorReversal;
        }

        /// <summary>
        /// デスクトラクタ
        /// </summary>
        ~ImageProcessing()
        {
        }

        /// <summary>
        /// 初期化
        /// </summary>
        public override void Init()
        {
            base.Init();
        }

        /// <summary>
        /// 画像処理の実行
        /// </summary>
        /// <param name="imageProcessingName">画像処理オブジェクトの名称</param>
        /// <param name="token">キャンセルトークン</param>
        /// <returns>実行結果 成功/失敗</returns>
        public override bool GoImageProcessing(string imageProcessingName, CancellationToken token)
        {
            int index = 0;
            bool result = false;

            switch (imageProcessingName)
            {
                case ComInfo.IMG_NAME_EDGE_DETECTION:
                    index = (int)ComInfo.ImgProcType.EdgeDetection;
                    var edgeDetection = (EdgeDetection)array[index];
                    result = edgeDetection.ImageProcessing(ref base.m_bitmap, token);
                    break;
                case ComInfo.IMG_NAME_GRAY_SCALE:
                    index = (int)ComInfo.ImgProcType.GrayScale;
                    var grayScale = (GrayScale)array[index];
                    result = grayScale.ImageProcessing(ref base.m_bitmap, token);
                    break;
                case ComInfo.IMG_NAME_BINARIZATION:
                    index = (int)ComInfo.ImgProcType.Binarization;
                    var binarization = (Binarization)array[index];
                    result = binarization.ImageProcessing(ref base.m_bitmap, token, Thresh);
                    break;
                case ComInfo.IMG_NAME_GRAY_SCALE_2DIFF:
                    index = (int)ComInfo.ImgProcType.GrayScale2Diff;
                    var grayScale2Diff = (GrayScale2Diff)array[index];
                    result = grayScale2Diff.ImageProcessing(ref base.m_bitmap, token);
                    break;
                case ComInfo.IMG_NAME_COLOR_REVERSAL:
                    index = (int)ComInfo.ImgProcType.ColorReversal;
                    var colorReversal = (ColorReversal)array[index];
                    result = colorReversal.ImageProcessing(ref base.m_bitmap, token);
                    break;
                default:
                    break;
            }

            return result;
        }
    }
}